#include "FileLoader.hpp"
#include <hackedit/common/logging/LoggingManager.hpp>
#include <QtCore/QUrl>
#include <QtCore/QFile>
#include <QtCore/QTextStream>
#include <QtCore/QTextCodec>
#include <QtConcurrent/QtConcurrent>

#include <chrono>
#include <thread>

USE_HACKEDIT_NAMESPACE2(Editor, Backend)
USE_HACKEDIT_NAMESPACE2(Common, Logging)

FileLoader::FileLoader(QObject* parent) :
        QObject(parent),
        _logger(LoggingManager::logger("HackEdit::Editor::Backend::FileLoader")),
        _complete(false),
        _isLoading(false),
        _document(nullptr),
        _loadFutureWatcher(new QFutureWatcher<QString>(this)) {
    connect(_loadFutureWatcher, &QFutureWatcher<QString>::finished, this, &FileLoader::onAsyncLoadFinished);
}

void FileLoader::classBegin() {

}

void FileLoader::componentComplete() {
    _complete = true;
    LOG_DEBUG(_logger, "componentComplete");
    loadFile();
}

const QString& FileLoader::path() const {
    return _path;
}

QString FileLoader::encoding() const {
    return _encoding;
}

TextDocument* FileLoader::document() const {
    return _document;
}

FileLoader::ErrorStatus FileLoader::errorStatus() const {
    return _errorStatus;
}

QString FileLoader::errorMessage() const {
    return _errorMessage;
}

bool FileLoader::isLoading() const {
    return _isLoading;
}

void FileLoader::setPath(const QString& path) {
    if (_path == path)
        return;

    _path = QUrl(path).toLocalFile();
    emit pathChanged(path);
    loadFile();
}

void FileLoader::setEncoding(const QString& encoding) {
    if (_encoding == encoding)
        return;

    _encoding = encoding;
    emit encodingChanged(encoding);
    loadFile();
}

void FileLoader::setDocument(TextDocument* document) {
    if (_document == document)
        return;

    _document = document;
    emit documentChanged(document);
    loadFile();
}

void FileLoader::onAsyncLoadFinished() {
    setIsLoading(false);
    _document->setText(_loadFutureWatcher->result());
}

void FileLoader::setIsLoading(bool isLoading) {
    if(isLoading == _isLoading )
        return;
    _isLoading = isLoading;
    isLoadingChanged();
}

void FileLoader::loadFile() {
    if (_complete && !_path.isEmpty() && _document != nullptr && !_isLoading) {
        setIsLoading(true);
        LOG_DEBUG(_logger, "loading file: " << _path << ", encoding=" << _encoding);
        _loadFuture = QtConcurrent::run(this, &FileLoader::loadFileAsync);
        _loadFutureWatcher->setFuture(_loadFuture);
    }
}

QString FileLoader::loadFileAsync() {
    QFile file(_path);

    // read file
    if (!file.open(QIODevice::ReadOnly)) {
        setError(OpenFileFailed, "Failed to open file " + _path + "\n Error: " + file.errorString());
        return "";
    }
    auto data = file.readAll();

    // decode
    auto codec = QTextCodec::codecForName(_encoding.toLocal8Bit());
    QTextCodec::ConverterState state;
    auto contents = codec->toUnicode(data.data(), data.size(), &state);
    if (state.invalidChars > 0) {
        setError(DecodingError, "Failed to decode file " + _path + " with encoding " + _encoding);
        return "";
    }
    std::this_thread::sleep_for(std::chrono::seconds(5));
    // todo: detect file encoding
    LOG_DEBUG(_logger, "Finished loading")
    resetError();
    return contents;
}

void FileLoader::setError(ErrorStatus errorStatus, const QString& errorMessage) {
    _errorStatus = errorStatus;
    _errorMessage = errorMessage;
    if (errorStatus != NoError && !_errorMessage.isEmpty()) {
        LOG_ERROR(_logger, _errorMessage);
        emit error();
    }
}

void FileLoader::resetError() {
    setError(NoError, "");
}

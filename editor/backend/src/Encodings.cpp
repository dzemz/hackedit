#include "Encodings.hpp"
#include <hackedit/common/logging/LoggingManager.hpp>
#include <QTextCodec>

USE_HACKEDIT_NAMESPACE2(Common, Logging)
USE_HACKEDIT_NAMESPACE2(Editor, Backend)

Encodings::Encodings(QObject* parent) :
        QObject(parent), _logger(LoggingManager::logger("Encodings")) {
    setCurrentEncoding(systemEncoding());
}

QStringList Encodings::availableEncodings() {
    QStringList codecs;
    for(QByteArray codec: QTextCodec::availableCodecs()) {
        codecs.append(QString::fromUtf8(codec));
    }
    return codecs;
}

QString Encodings::systemEncoding() {
    return QString::fromUtf8(QTextCodec::codecForLocale()->name());
}

void Encodings::setCurrentEncoding(const QString& codec) {
    if (codec == _currentEncoding)
        return;

    QString message = "Current encoding changed from " + _currentEncoding + " to " + codec;
    if (_currentEncoding.isEmpty())
        message = "Current encoding set to " + codec;
    LOG_DEBUG(_logger, message);

    _currentEncoding = codec;
    emit currentEncodingChanged(codec);
}

QString Encodings::currentEncoding() {
    return _currentEncoding;
}

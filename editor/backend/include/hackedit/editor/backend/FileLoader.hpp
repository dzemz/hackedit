#pragma once

#include <future>
#include <QObject>
#include <QQmlParserStatus>
#include <QtConcurrent>
#include <hackedit/common/HackEditNamespace.hpp>
#include <hackedit/common/logging/ILogger.hpp>
#include <hackedit/editor/backend/TextDocument.hpp>
#include <hackedit/editor/backend/EndOfLine.hpp>

BEGIN_HACKEDIT_NAMESPACE2(Editor, Backend)

class FileLoader: public QObject, public QQmlParserStatus {
    Q_OBJECT
    Q_INTERFACES(QQmlParserStatus)
    Q_PROPERTY(QString path READ path WRITE setPath NOTIFY pathChanged)
    Q_PROPERTY(QString encoding READ encoding WRITE setEncoding NOTIFY encodingChanged)
    Q_PROPERTY(EndOfLine::Convention endOfLineConvention
                       READ endOfLineConvention
                       WRITE setEndOfLineConvention
                       NOTIFY endOfLineConventionChanged)
    Q_PROPERTY(TextDocument* document READ document WRITE setDocument NOTIFY documentChanged)
    Q_PROPERTY(ErrorStatus errorStatus READ errorStatus CONSTANT)
    Q_PROPERTY(QString errorMessage READ errorMessage CONSTANT)
    Q_PROPERTY(bool isLoading READ isLoading WRITE setIsLoading NOTIFY isLoadingChanged)
public:
    enum ErrorStatus {
        NoError,
        OpenFileFailed,
        SaveFileFailed,
        DecodingError,
        EncodingError,
    };
    Q_ENUMS(ErrorStatus)

    FileLoader(QObject* parent=nullptr);

    void classBegin() override;
    void componentComplete() override;

    const QString& path() const;
    QString encoding() const;
    TextDocument* document() const;
    ErrorStatus errorStatus() const;
    QString errorMessage() const;
    bool isLoading() const;

public slots:
    void setPath(const QString& path);
    void setEncoding(const QString& encoding);
    void setDocument(TextDocument* document);

private slots:
    void onAsyncLoadFinished();
    void setIsLoading(bool isLoading);

signals:
    void pathChanged(QString path);
    void encodingChanged(QString encoding);
    void endOfLineConventionChanged();
    void documentChanged(TextDocument* document);
    void isLoadingChanged();
    void error();

private:
    void loadFile();
    QString loadFileAsync();

    void setError(ErrorStatus errorStatus, const QString& errorMessage);
    void resetError();

    std::shared_ptr<Common::Logging::ILogger> _logger;
    bool _complete;
    bool _isLoading;
    QString _path;
    QString _encoding;
    TextDocument* _document;
    ErrorStatus _errorStatus;
    QString _errorMessage;
    QFutureWatcher<QString>* _loadFutureWatcher;
    QFuture<QString> _loadFuture;
};

END_HACKEDIT_NAMESPACE2

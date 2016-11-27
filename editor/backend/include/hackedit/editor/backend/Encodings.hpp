#pragma once

#include <memory>
#include <QObject>
#include <hackedit/common/HackEditNamespace.hpp>
#include <hackedit/common/logging/ILogger.hpp>

BEGIN_HACKEDIT_NAMESPACE2(Editor, Backend)

class Encodings: public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString currentEncoding READ currentEncoding WRITE setCurrentEncoding NOTIFY currentEncodingChanged)
public:
    Encodings(QObject* parent= nullptr);
    QString currentEncoding();

    Q_INVOKABLE QStringList availableEncodings();
    Q_INVOKABLE QString systemEncoding();

public slots:
    void setCurrentEncoding(const QString& codec);

signals:
    void currentEncodingChanged(const QString& codec);

private:
    std::shared_ptr<Common::Logging::ILogger> _logger;
    QString _currentEncoding;
};

END_HACKEDIT_NAMESPACE2
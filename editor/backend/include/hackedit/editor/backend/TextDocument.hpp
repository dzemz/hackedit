#pragma once

#include <QObject>
#include <hackedit/common/HackEditNamespace.hpp>
#include <hackedit/common/logging/ILogger.hpp>
#include <hackedit/editor/backend/DllDefines.hpp>
#include <memory>

BEGIN_HACKEDIT_NAMESPACE2(Editor, Backend)

class BACKEND_EXPORT TextDocument: public QObject {
Q_OBJECT
    Q_PROPERTY(QString text READ text WRITE setText NOTIFY textChanged)
public:
    TextDocument(QObject* parent= nullptr);
    QString text() const;

public slots:
    void setText(QString text);

signals:
    void textChanged(QString text);

private:
    QString _text;
    std::shared_ptr<Common::Logging::ILogger> _logger;
};

END_HACKEDIT_NAMESPACE2
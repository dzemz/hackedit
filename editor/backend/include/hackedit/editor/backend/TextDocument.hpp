#pragma once

#include <QObject>
#include <hackedit/editor/backend/DllDefines.hpp>
#include <hackedit/common/logging/ILogger.hpp>
#include <memory>

namespace hackedit {
    namespace editor {
        namespace backend {
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
                std::shared_ptr<common::logging::ILogger> _logger;
            };
        }
    }
}

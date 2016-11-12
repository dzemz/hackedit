#pragma once

#include <QObject>
#include <hackedit/editor/backend/DllDefines.hpp>

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
            };
        }
    }
}

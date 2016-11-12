#pragma once

#include <QtQml/qqml.h>
#include <QtQml/QQmlExtensionPlugin>
#include "DllDefines.hpp"

namespace hackedit {
    namespace editor {
        namespace frontend {
            class FRONTEND_EXPORT EditorPlugin: public QQmlExtensionPlugin {
            Q_OBJECT
                Q_PLUGIN_METADATA(IID QQmlExtensionInterface_iid)
            public:
                void registerTypes(const char *uri);
            };
        }
    }
}

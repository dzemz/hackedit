#pragma once

#include <hackedit/common/HackEditNamespace.hpp>
#include <QtQml/qqml.h>
#include <QtQml/QQmlExtensionPlugin>
#include "Exports.hpp"

BEGIN_HACKEDIT_NAMESPACE2(Editor, Frontend)

class FRONTEND_EXPORT EditorPlugin: public QQmlExtensionPlugin {
Q_OBJECT
    Q_PLUGIN_METADATA(IID QQmlExtensionInterface_iid)
public:
    void registerTypes(const char *uri) override ;
    void initializeEngine(QQmlEngine* engine, const char* uri) override;
};

END_HACKEDIT_NAMESPACE2

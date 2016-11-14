#pragma once

#include <hackedit/common/HackEditNamespace.hpp>
#include <QtQml/qqml.h>
#include <QtQml/QQmlExtensionPlugin>
#include "Exports.hpp"

BEGIN_HACKEDIT_NAMESPACE2(Common, Controls)

class HACKEDIT_COMMON_CONTROLS_EXPORT Plugin: public QQmlExtensionPlugin {
Q_OBJECT
    Q_PLUGIN_METADATA(IID QQmlExtensionInterface_iid)
public:
    void registerTypes(const char *uri);
};

END_HACKEDIT_NAMESPACE2

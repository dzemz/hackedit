#include "EditorPlugin.hpp"
#include <hackedit/editor/backend/TextDocument.hpp>

using namespace hackedit::editor::frontend;
using namespace hackedit::editor::backend;

void EditorPlugin::registerTypes(const char *uri) {
    qmlRegisterType<TextDocument>(uri, HACKEDIT_VERSION_MAJOR, HACKEDIT_VERSION_MINOR, "TextDocument");
}

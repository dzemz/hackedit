#include "EditorPlugin.hpp"
#include <hackedit/editor/backend/TextDocument.hpp>

USE_HACKEDIT_NAMESPACE2(Editor, Backend)
USE_HACKEDIT_NAMESPACE2(Editor, Frontend)

void EditorPlugin::registerTypes(const char *uri) {
    qmlRegisterType<TextDocument>(uri, HACKEDIT_VERSION_MAJOR, HACKEDIT_VERSION_MINOR, "TextDocument");
}

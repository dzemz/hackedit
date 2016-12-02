#include "EditorPlugin.hpp"
#include <hackedit/editor/backend/Encodings.hpp>
#include <hackedit/editor/backend/FileLoader.hpp>
#include <hackedit/editor/backend/TextDocument.hpp>
#include <QQmlEngine>
#include <QQmlContext>

USE_HACKEDIT_NAMESPACE2(Editor, Backend)
USE_HACKEDIT_NAMESPACE2(Editor, Frontend)

void EditorPlugin::registerTypes(const char *uri) {
    qmlRegisterType<TextDocument>(uri, HACKEDIT_VERSION_MAJOR, HACKEDIT_VERSION_MINOR, "TextDocument");
    qmlRegisterType<FileLoader>(uri, HACKEDIT_VERSION_MAJOR, HACKEDIT_VERSION_MINOR, "FileLoader");
}

void EditorPlugin::initializeEngine(QQmlEngine* engine, const char* uri) {
    QQmlExtensionPlugin::initializeEngine(engine, uri);
    engine->rootContext()->setContextProperty("encodings", new Encodings);
}

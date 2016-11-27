#include "TextDocument.hpp"
#include <hackedit/common/logging/LoggingManager.hpp>

USE_HACKEDIT_NAMESPACE2(Common, Logging)
USE_HACKEDIT_NAMESPACE2(Editor, Backend)

TextDocument::TextDocument(QObject *parent) : QObject(parent), _logger(LoggingManager::logger("TextDocument")) {

}

QString TextDocument::text() const {
    return _text;
}

void TextDocument::setText(QString text) {
    if (_text == text)
        return;

    _text = text;
    LOG_DEBUG(_logger, "Text changed: " << text);
    emit textChanged(text);
}

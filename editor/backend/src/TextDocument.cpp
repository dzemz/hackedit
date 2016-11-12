#include "TextDocument.hpp"
#include <hackedit/common/logging/LoggingManager.hpp>

using namespace hackedit::editor::backend;
using namespace hackedit::common::logging;

TextDocument::TextDocument(QObject *parent) : QObject(parent), _logger(LoggingManager::logger("TextDocument")) {

}

QString TextDocument::text() const {
    return _text;
}

void TextDocument::setText(QString text) {
    if (_text == text)
        return;

    _text = text;
    LOG_DEBUG(_logger, "Text changed: " << text.toStdString());
    emit textChanged(text);
}

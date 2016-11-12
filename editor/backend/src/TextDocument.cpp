#include "TextDocument.hpp"

using namespace hackedit::editor::backend;

TextDocument::TextDocument(QObject *parent) : QObject(parent) {

}

QString TextDocument::text() const {
    return _text;
}

void TextDocument::setText(QString text) {
    if (_text == text)
        return;

    _text = text;
    emit textChanged(text);
}

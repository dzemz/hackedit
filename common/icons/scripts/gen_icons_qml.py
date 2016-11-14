#!/usr/bin/python3
"""
Helper script that helps updating the file-icons icon font.
Unfortunately, the qt font loader fails to load the woff2 font. The easies solution is to manually convert
file-icons.woff2 to a .ttf font.
"""
import glob
import re
import os

import shutil

QML_HEADER = """pragma Singleton
import QtQuick 2.7

Item {
    readonly property string family: "HackEditIcons"

    property var loader: FontLoader { source: "qrc:/hackedit/fonts/MaterialIcons-Regular.ttf" }

    readonly property var icons: {
"""
ICON_ENTRY = '            "%(name)s": {"fontFamily": "%(fontFamily)s", "value": "%(value)s"},\n'

def read_material_icons_spec(existing_names):
    qml_content = ''
    with open(os.path.join(os.getcwd(), 'scripts', 'MaterialIcons-Regular.codepoints')) as f:
        lines = f.read().splitlines()
    for l in lines:
        name, value = l.strip().split(' ')
        name = name.replace('-', '_').replace(' ', '_')
        if name in existing_names:
            print('warning: icon name already used: %r, this icon will be ignored...' % name)
            continue
        existing_names.add(name)
        qml_content += ICON_ENTRY % {
            'name': '%s' % name,
            'fontFamily': 'Material Icons, Regular',
            'value': '\\u%s' % value
        }
    return qml_content


def main():
    if os.getcwd().endswith('scripts'):
        os.chdir("..")
    qml_path = os.path.join(os.getcwd(), 'qml/HackEditIcons.qml')
    qml_content = QML_HEADER
    existing_name = set()
    qml_content += read_material_icons_spec(existing_name)

    qml_content += "     }\n}\n"

    with open(qml_path, "w") as f:
        f.write(qml_content)

if __name__ == '__main__':
    main()
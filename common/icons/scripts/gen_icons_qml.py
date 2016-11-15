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
    readonly property string family: "%s"
    property var loader: FontLoader { source: "%s" }

"""
ICON_ENTRY = '    readonly property string %(name)s: "%(value)s"\n'


def generate_material_design_icons(existing_names):
    font_family = 'Material Icons, Regular'
    qrc_font = 'qrc:/hackedit/fonts/MaterialIcons-Regular.ttf'
    qml_content = QML_HEADER % (font_family, qrc_font)
    with open(os.path.join(os.getcwd(), 'scripts', 'MaterialIcons-Regular.codepoints')) as f:
        lines = f.read().splitlines()
    for l in lines:
        name, value = l.strip().split(' ')
        name = 'icon_%s' % name.replace('-', '_').replace(' ', '_')
        if name in existing_names:
            print('warning: icon name already used: %r, this icon will be ignored...' % name)
            continue
        existing_names.add(name)
        qml_content += ICON_ENTRY % {'name': '%s' % name, 'value': '\\u%s' % value}
    qml_content += "}\n"
    qml_path = os.path.join(os.getcwd(), 'qml/MaterialIcons.qml')
    with open(qml_path, "w") as f:
        f.write(qml_content)
    return qml_content


def main():
    if os.getcwd().endswith('scripts'):
        os.chdir("..")
    existing_name = set()
    generate_material_design_icons(existing_name)

if __name__ == '__main__':
    main()
import QtQuick 2.7
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.0
import QtQuick.Controls.Material 2.0
import HackEdit.Editor 0.1
import HackEdit.Common 0.1


ApplicationWindow {
    visible: true
    width: 1280
    height: 720
    property bool dark: true
    Material.theme: dark ? Material.Dark : Material.Light
    Material.accent: dark ? Material.LightBlue: Material.Blue
    Material.primary: Material.background

    header: ToolBar {
        id: toolBar
        property int iconSize: 18
        RowLayout {
            anchors.fill: parent
            ToolButton {
                text: HackEditIcons.icons.create.value
                font.family: HackEditIcons.icons.create.fontFamily
                font.pixelSize: toolBar.iconSize
            }
            ToolButton {
                text: HackEditIcons.icons.folder_open.value
                font.family: HackEditIcons.icons.folder_open.fontFamily
                font.pixelSize: toolBar.iconSize
            }
            ToolButton {
                text: HackEditIcons.icons.save.value
                font.family: HackEditIcons.icons.save.fontFamily
                font.pixelSize: toolBar.iconSize
            }
            Item {
                Layout.preferredWidth: 7
                Layout.fillHeight: true

                Rectangle {
                    anchors.centerIn: parent
                    anchors.margins: 3
                    height: 22
                    width: 1
                    color: Material.color(Material.Grey)
                }
            }
            ToolButton {
                text: HackEditIcons.icons.undo.value
                font.family: HackEditIcons.icons.undo.fontFamily
                font.pixelSize: toolBar.iconSize
            }
            ToolButton {
                text: HackEditIcons.icons.redo.value
                font.family: HackEditIcons.icons.redo.fontFamily
                font.pixelSize: toolBar.iconSize
            }
            Item { Layout.fillWidth: true }
            ToolButton {
                text: HackEditIcons.icons.menu.value
                font.family: HackEditIcons.icons.menu.fontFamily
                font.pixelSize: toolBar.iconSize
            }
        }
    }

    CodeEditor {
        anchors.fill: parent
    }
}

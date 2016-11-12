import QtQuick 2.7
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.0
import QtQuick.Controls.Material 2.0
import HackEdit.Editor 0.1

ApplicationWindow {
    visible: true
    width: 1280
    height: 720
    property bool dark: true
    Material.theme: dark ? Material.Dark: Material.Light
    Material.accent: Material.LightBlue
    Material.primary: Material.background


    header: ToolBar {
        RowLayout {
            anchors.fill: parent
            ToolButton {
                text: qsTr("New")
            }
            ToolButton {
                text: qsTr("Open")
            }
            ToolButton {
                text: qsTr("Save")
            }
            ToolButton {
                text: qsTr("Save as")
            }
            Item {
                Layout.preferredWidth: 7
                Layout.fillHeight: true

                Rectangle {
                    anchors.centerIn: parent
                    anchors.margins: 3
                    height: 22
                    width: 1
                    color: Material.Grey
                }
            }
            ToolButton {
                text: qsTr("Undo")
            }
            ToolButton {
                text: qsTr("Redo")
            }
            Item { Layout.fillWidth: true }
            ToolButton {
                text: qsTr("Menu")
            }
        }

    }

    CodeEditor {
        anchors.fill: parent
    }
}

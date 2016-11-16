import QtQuick 2.7
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.0
import QtQuick.Controls.Material 2.0
import HackEdit.Editor 0.1
import HackEdit.Common.Icons 0.1


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
                text: MaterialIcons.icon_create
                font.family: MaterialIcons.family
                font.pixelSize: toolBar.iconSize

                onClicked: newDocument();
                Shortcut {
                    sequence: StandardKey.New
                    onActivated: newDocument();
                }
            }

            ToolButton {
                text: MaterialIcons.icon_folder_open
                font.family: MaterialIcons.family
                font.pixelSize: toolBar.iconSize

                onClicked: openDocument()
                Shortcut {
                    sequence: StandardKey.Open
                    onActivated: openDocument()
                }
            }
            ToolButton {
                text: MaterialIcons.icon_save
                font.family: MaterialIcons.family
                font.pixelSize: toolBar.iconSize

                onClicked: saveDocument()
                Shortcut {
                    sequence: StandardKey.Save
                    onActivated: saveDocument()
                }
            }
            // separator
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
                text: MaterialIcons.icon_undo
                font.family: MaterialIcons.family
                font.pixelSize: toolBar.iconSize

                onClicked: undo()
                Shortcut {
                    sequence: StandardKey.Undo
                    onActivated: undo()
                }
            }
            ToolButton {
                text: MaterialIcons.icon_redo
                font.family: MaterialIcons.family
                font.pixelSize: toolBar.iconSize

                onClicked: redo()
                Shortcut {
                    sequence: StandardKey.Redo
                    onActivated: redo()
                }
            }
            Item { Layout.fillWidth: true }
            ToolButton {
                text: MaterialIcons.icon_menu
                font.family: MaterialIcons.family

                font.pixelSize: toolBar.iconSize
                onClicked: console.log("open menu")
            }
        }
    }

    Text {
        anchors.centerIn: parent
        font.pixelSize: 72
        color: 'red'
        text: MaterialIcons.icon_menu
        font.family: MaterialIcons.family
    }

    function newDocument() {
        console.log("Creating a new document");
    }

    function openDocument() {
        console.log("Opening an existing document");
    }

    function saveDocument() {
        console.log("Saving document");
    }

    function undo() {
        console.log("Undo");
    }

    function redo() {
        console.log("Redo");
    }


    CodeEditor {
        anchors.fill: parent
    }
}

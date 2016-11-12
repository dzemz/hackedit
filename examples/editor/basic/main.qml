import QtQuick 2.7
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.0
import QtQuick.Controls.Material 2.0
import HackEdit.Editor 0.1

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    property bool dark: true
    Material.theme: dark ? Material.Dark: Material.Light
    Material.accent: Material.LightBlue

    RowLayout {
        anchors.fill: parent
        anchors.margins: 9
        Button { }
        CheckBox{ }
        Switch { }
        ComboBox { model: ["First", "Second", "Third"] }
        CodeEditor {
            Layout.fillHeight: true
            Layout.fillWidth: true

            BusyIndicator {
             anchors.centerIn: parent
            }
        }
    }
}

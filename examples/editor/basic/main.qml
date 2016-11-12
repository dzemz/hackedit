import QtQuick 2.7
import QtQuick.Controls 2.0
import HackEdit.Editor 0.1

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    
    CodeEditor {
        anchors.fill: parent
    }
}

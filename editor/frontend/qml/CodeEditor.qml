import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Dialogs 1.1

import HackEdit.Editor 0.1

Pane {
    id: root
    property var document: TextDocument {
        text: "Hello world"
    }

    MessageDialog {
        id: errorDialog
        icon: StandardIcon.Critical
    }

    property var file: FileLoader {
        document: root.document
        encoding: encodings.currentEncoding
        onError: {
            errorDialog.title = errorStatus == FileLoader.OpenFileFailed ? "Failed to open file" : "Other error";
            errorDialog.text = errorMessage;
            errorDialog.visible = true;
        }
    }

    BusyIndicator {
        anchors.centerIn: parent
        visible: file.isLoading
    }
}

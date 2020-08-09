import QtQuick 2.12
import QtQuick.Controls 2.12
import Nebulus 1.0

ApplicationWindow {
    id: applicationWindow
    visible: true
    width: 800
    height: 400
    minimumWidth: 800
    minimumHeight: 400
    title: qsTr(" ")

    background: Rectangle {
        color: "transparent"
    }

    ApplicationLoader {
        id: applicationLoader
    }

    QmlFileProcessor {
        id: qmlFileProcessor
    }

    Text {
        id: headerTitle
        text: qsTr("Nebulus platform")
        font.pixelSize: 22
        anchors.left: parent.left
        anchors.top: parent.top
        anchors.leftMargin: 24
        anchors.topMargin: 24
    }

    Text {
        id: headerProcess
        text: qsTr("Downloading files 1 of 10")
        anchors.top: headerTitle.bottom
        anchors.left: parent.left
        anchors.topMargin: 16
        anchors.leftMargin: 54
        font.pixelSize: 14
    }

    Text {
        id: downloadingProgressLabel
        anchors.top: headerProcess.bottom
        anchors.topMargin: 24
        anchors.left: parent.left
        anchors.leftMargin: 54
        font.pixelSize: 12
        text: "Downloading completed"
    }

    ProgressBar {
        id: downloadProgress
        anchors.top: downloadingProgressLabel.bottom
        anchors.topMargin: 8
        anchors.left: parent.left
        anchors.leftMargin: 54
        width: parent.width - 54 * 2
        value: .5
    }

    Text {
        id: processingProgressLabel
        anchors.top: downloadProgress.bottom
        anchors.topMargin: 24
        anchors.left: parent.left
        anchors.leftMargin: 54
        font.pixelSize: 12
        text: "Installing completed"
    }

    ProgressBar {
        id: installedProgress
        anchors.top: processingProgressLabel.bottom
        anchors.topMargin: 8
        anchors.left: parent.left
        anchors.leftMargin: 54
        width: parent.width - 54 * 2
        value: .5
    }

    footer: Rectangle {
        id: rect
        color: "#E3D7C5"
        width: parent.width
        height: 50
        anchors.bottom: parent.bottom

        Text {
            id: headerText
            anchors.left: parent.left
            anchors.leftMargin: 20
            anchors.verticalCenter: parent.verticalCenter
            font.pixelSize: 12
            text: qsTr("platform version 1.0")
        }
        Text {
            id: currentOperation
            anchors.right: parent.right
            anchors.rightMargin: 20
            anchors.verticalCenter: parent.verticalCenter
            font.pixelSize: 12
            text: qsTr("No operations")
        }
    }
}

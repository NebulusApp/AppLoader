import QtQuick 2.12
import QtQuick.Controls 2.12
import QtGraphicalEffects 1.0
import Nebulus 1.0

ApplicationWindow {
    id: applicationWindow
    visible: true
    width: 620
    height: 120
    title: qsTr("Application Loader")
    flags: Qt.FramelessWindowHint | Qt.Window

    background: Rectangle {
        color: "transparent"
    }

    ApplicationLoader {
        id: applicationLoader
    }

    QmlFileProcessor {
        id: qmlFileProcessor
    }

    Rectangle {
        id: rect
        anchors.fill: parent
        anchors.margins: 2
        MouseArea {
            anchors.fill: parent

            property int dx
            property int dy

            onPressed: {
                dx = mouseX;
                dy = mouseY
            }
            onPositionChanged: {
                applicationWindow.x += mouseX - dx
                applicationWindow.y += mouseY - dy
            }
        }
        Text {
            id: headerText
            anchors.top: parent.top
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.topMargin: 6
            text: qsTr("Load application name")
        }
        Text {
            id: currentOperation
            anchors.centerIn: parent
            font.pixelSize: 20
            text: qsTr("Current operation")
        }
        Text {
            id: processedFile
            anchors.bottom: parent.bottom
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.bottomMargin: 6
            text: qsTr("Current processed file")
        }
    }

    DropShadow {
        anchors.fill: rect
        horizontalOffset: 1
        verticalOffset: 1
        radius: 5
        samples: 10
        source: rect
        color: "black"
    }
}

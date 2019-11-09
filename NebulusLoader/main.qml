import QtQuick 2.12
import QtQuick.Controls 2.12
import QtGraphicalEffects 1.0

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

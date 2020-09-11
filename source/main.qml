import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.2
import QtQuick.Controls.Universal 2.2
import QtQuick.Layouts 1.3
import "./"
import "./common"
import Flux 1.0
Window {
    id: startedWindow
    visible: true

    property string currentDateString

    readonly property int resolution: 1
    readonly property real appWidthResolution: resolution == 1 ? 1024 : 1920
    readonly property real appHeightResolution: resolution == 1 ? 728 : 1080
    width: appWidthResolution
    height: appHeightResolution
    title: qsTr("APP")

    property bool isVisibleFooter: false
    property bool isNormalMode: true
    readonly property real defaultWidth: appWidthResolution
    readonly property real defaultHeight: appHeightResolution
    property real scaleWidthRatio: startedWindow.width/defaultWidth
    property real scaleHeightRatio: startedWindow.height/defaultHeight
    property real scaleRatio: scaleHeightRatio < scaleWidthRatio ? scaleHeightRatio : scaleWidthRatio

    property real fontDefaultSize : 10 * scaleRatio
    property color backgroundColor: "#000000"

    Universal.theme: Universal.Dark
    Universal.accent: Universal.Cyan

    Rectangle {
        anchors.fill: parent
        color: backgroundColor
    }
    Loader {
        id: mainLoader
        focus: true
        anchors.fill: parent

        source: "qrc:/HomeForm.qml"
        property bool valid: item !== null
    }


    CustomDialog {
        id: confirmExit
        width: startedWindow.width * 4 / 10
        height: startedWindow.height * 3 / 10
        x: Math.round((startedWindow.width - width) / 2)
        y: Math.round((startedWindow.height - height) / 2)
        closePolicy: Popup.CloseOnEscape
        modal: true
        focus: true
        title: "Thông báo"
        visible: false
        buttons: dialogs.OK
        contentItem: Rectangle {
            color: "transparent"
            Label {
                anchors.centerIn: parent
                anchors.fill: parent
                wrapMode: Text.WordWrap
                text: "Bạn có muốn thoát chương trình?"
            }
        }

        onAccepted: {
            confirmExit.visible = false
            ActionProvider.exitApplication()
        }

        onRejected: {
            confirmExit.visible = false
        }
    }

    Component.onCompleted: {
        //declare healthStatusWindow
        console.log("onCompleted")
    }
}

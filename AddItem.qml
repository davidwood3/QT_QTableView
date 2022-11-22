import QtQuick 2.9
import QtQuick.Controls 2.5
Item {
    Frame {
        id: frame
        x: 145
        y: -40
        width: 376
        height: 396
        opacity: 0.5

        TextField {
            id: textField
            x: 39
            y: 67
            width: 226
            height: 36
            font.pointSize: 20
            placeholderText: qsTr("First Name")
        }

        Label {
            id: label
            font: 20
            x: 42
            y: 24
            width: 158
            height: 0
            text: qsTr("First Name")
            font.pointSize: 20
        }

        Label {
            id: label1
            x: 35
            y: 117
            width: 139
            height: 43
            text: qsTr("Last Name")
            font.pointSize: 20
        }

        TextField {
            id: textField1
            x: 34
            y: 163
            width: 226
            height: 34
            opacity: 0.5
            text: "Last Name"
            font.pointSize: 20
            placeholderText: qsTr("Text Field")
        }
    }

}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/

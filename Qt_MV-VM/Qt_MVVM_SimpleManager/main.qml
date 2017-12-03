import QtQuick 2.4
import QtQuick.Window 2.2

Window {
	visible: true
	width: 480
	height: 272
//	title: qsTr("Hello World")

	MouseArea {
		anchors.fill: parent
		onClicked: {
			console.log(qsTr('Clicked on background main.qml. Text: "' + textEdit.text + '"'))
		}
	}

	TextEdit {
		id: textEdit
		text: qsTr("Enter some text...")
		verticalAlignment: Text.AlignVCenter
		anchors.top: parent.top
		anchors.horizontalCenter: parent.horizontalCenter
		anchors.topMargin: 20
		Rectangle {
			anchors.fill: parent
			anchors.margins: -10
			color: "transparent"
			border.width: 1
		}
	}
}

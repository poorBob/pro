//ScreenB
import QtQuick 2.0
import QtQuick.Controls 1.2
import QtQuick.Window 2.2

Rectangle {
	id: root
	width: 480
	height: 272
	color: "lightgreen"

	signal goToScreen(string url)

	Text {
		id: txt
		anchors.centerIn: parent
		text: "Screen B. Action in " + vm.clickLeft + " cliks! "
	}

	Button
	{
		id: btn
		anchors.top: txt.bottom
		anchors.topMargin: 10
		anchors.horizontalCenter: parent.horizontalCenter
		text: "Button - Click Me!"
		onClicked: {
			goToScreen("ScreenA.qml")
			vm.onButtonClicked()
		}
	}

	Component.onCompleted:
	{
		console.log("Screen B  created!")
	}
}

//ScreenA
import QtQuick 2.0
import QtQuick.Controls 1.2
import QtQuick.Window 2.2

Rectangle {
	id: root
	width: 480
	height: 272
	color: "yellow"

	signal goToScreen(string url)

	Text {
		id: txt
		anchors.centerIn: parent
		text: "Screen A. Action in " + vm.clickLeft + " cliks! "
	}

	Button
	{
		id: btn
		anchors.top: txt.bottom
		anchors.topMargin: 10
		anchors.horizontalCenter: parent.horizontalCenter
		text: "Button - Click Me!"
		onClicked: {
			goToScreen("ScreenB.qml")
			vm.onButtonClicked()
		}
	}

	Button
	{
		id: btnGoToB
		anchors.left: btn.right
		anchors.top: btn.top
//		anchors.verticalCenter: parent.verticalCenter
		text: "Go to B"
		onClicked: {
			goToScreen("ScreenB.qml")
			vm.onGoToBButtonClicked()
		}
	}

	Component.onCompleted:
	{
		console.log("Screen A  created!")
	}
}
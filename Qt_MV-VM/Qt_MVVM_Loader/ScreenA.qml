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
		text: "Screen A. Action in " + screenADataContext.clickLeft + " cliks! "
	}

	Button
	{
		id: btn
		anchors.top: txt.bottom
		anchors.topMargin: 10
		anchors.horizontalCenter: parent.horizontalCenter
		text: "Counter Button - Click Me!"
		onClicked: {
//			goToScreen("ScreenB.qml")
			screenADataContext.onCounterButtonClicked()
		}
	}

	Button
	{
		id: btnGoToB
		anchors.left: btn.right
		anchors.top: btn.top
//		anchors.verticalCenter: parent.verticalCenter
		text: "Go to screen B"
		onClicked: {
//			goToScreen("ScreenB.qml")
			screenADataContext.onGoToBButtonClicked()
		}
	}

	Component.onCompleted:
	{
		console.log("Screen A  created!")
	}
}

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
		text: "Screen B. Action in " + screenBDataContext.clickLeft + " cliks! "
	}

	Button
	{
		id: btn
		anchors.top: txt.bottom
		anchors.topMargin: 10
		anchors.horizontalCenter: parent.horizontalCenter
		text: "Counter Button - Click Me!"
		onClicked: {
//			goToScreen("ScreenA.qml")
			screenBDataContext.onCounterButtonClicked()
		}
	}

	Button
	{
		id: btnGoToA
		anchors.left: btn.right
		anchors.top: btn.top
		text: "Go to screen A"
		onClicked: {
			screenBDataContext.onGoToAButtonClicked()
		}
	}

	Component.onCompleted:
	{
		console.log("Screen B  created!")
	}
}

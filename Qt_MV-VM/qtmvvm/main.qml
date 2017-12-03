import QtQuick 2.4
import QtQuick.Window 2.2
import QtQuick.Layouts 1.1

Window {
	visible: true
	width: 480
	height: 272
	title: qsTr("Hello World")

	MouseArea {
		anchors.fill: parent
		onClicked: {
			console.log(qsTr('Clicked on background.'))
		}
	}

	RowLayout {
		id: rowLayout
		anchors.fill: parent
		anchors.leftMargin: 25

		Column {
			id: columnAlpha
			width: 200
			height: 400

			Text {
				id: labelAlpha
				width: 108
				height: 36
				text: qsTr("Random Alpha:")
				font.pixelSize: 12
			}

			Text {
				id: valueAlpha
				text: randVM.randomAlpha
				font.pixelSize: 12
			}
		}

		Column {
			id: columnBeta
			width: 200
			height: 400

			Text {
				id: labelBeta
				width: 108
				height: 36
				text: qsTr("Random Beta:")
				font.pixelSize: 12
			}

			Text {
				id: valueBeta
				text: randVM.randomBeta
				font.pixelSize: 12
			}
		}

		Column {
			id: columnGamma
			width: 200
			height: 400

			Text {
				id: labelGamma
				width: 108
				height: 36
				text: qsTr("Random Gamma:")
				font.pixelSize: 12
			}

			Text {
				id: valueGamma
				text: randVM.randomGamma
				font.pixelSize: 12
			}
		}
	}
}

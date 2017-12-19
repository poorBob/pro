import QtQuick 2.4
import QtQuick.Window 2.2
import QtQuick.Controls 2.2

Window {
	id: root
	visible: true
	width: 480
	height: 272

//	Loader {
//		id: loader
//		source: viewMgr.source
//		asynchronous: true
////		visible: status == Loader.Ready
//		onStatusChanged : {

////			status == Loader.Ready ? animation.running = true : animation.running = false
//			status == Loader.Ready ? propAnimation.running = true : propAnimation.running = false
//		}

//		onLoaded:
//		{
//			console.log("Loader has loaded following screen: ", source)
//		}

//	}

	property var rightAnim: true;
	property int  dur: 350

	property var source: viewMgr.source

	function myQmlFunction(msg) {
		console.log("Got message:", msg)
		stack.replace(msg)
		return "some return value"
	}

	onSourceChanged: {
		console.log("source changed", source)
	}

	Transition {
		id: enterNext
		        XAnimator {
					from: (stack.mirrored ? -1 : 1) * -stack.width
					to: 0
					duration: dur
					easing.type: Easing.OutCubic
				}
	        }

	Transition {
		id: enterPrevious
		        XAnimator {
					from: (stack.mirrored ? -1 : 1) * stack.width
					to: 0
					duration: dur
					easing.type: Easing.OutCubic
				}
	        }

	Transition {
		id: exitNext
		        XAnimator {
					from: 0
					to: (stack.mirrored ? -1 : 1) * stack.width
					duration: dur
					easing.type: Easing.OutCubic
				}
	        }

	Transition {
		id: exitPrevious
		        XAnimator {
					from: 0
					to: (stack.mirrored ? -1 : 1) * -stack.width
					duration: dur
					easing.type: Easing.OutCubic
				}
	        }

	StackView {
		id: stack
		initialItem: mainView
		anchors.fill: parent

		replaceEnter: rightAnim ? enterNext : enterPrevious

		replaceExit: rightAnim ? exitNext : exitPrevious
	}

	Component {
		   id: mainView

		   Row {
			   spacing: 10

			   Button {
				   text: "Prev"
//				   enabled: stack.depth > 1

				   onClicked: {
					   rightAnim = true
					   viewMgr.onPrevClicked()
					   stack.replace(source)
				   }

			   }

			   Button {
				   text: "Next"

				   onClicked: {
					   rightAnim = false
//					   viewMgr.onNextClicked()
//					   stack.replace(source)
					   stack.replace("ScreenA.qml"/*, StackView.Immediate*/)

				   }
//				   next: true
			   }

			   Text {
				   text: stack.depth
			   }
		   }
	   }

	// pomysl: zrobic cos jakby proste stackView, ale tylko z 3 widokami: previousItem, currentItem, nextItem i te
	// 3 widoki wykorzystac w animacjach

//	NumberAnimation {
//		id: animation
//		target: loader.item
//		property: "x"
//		from: 0
//		to: root.width - 500
//		duration: 1000
//		easing.type: Easing.InExpo

//		onStarted: { console.log("started!") }
//	}

//	PropertyAnimation {
//		id: propAnimation
//		target: loader.item
//		property: "x"
//		from: target.width
//		to: 0
//		duration: 1000
//		easing.type: Easing.OutCubic

//		onStarted: { console.log("propAnimation started!") }
//	}
}

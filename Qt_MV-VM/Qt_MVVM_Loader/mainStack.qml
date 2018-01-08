import QtQuick 2.4
import QtQuick.Window 2.2
import QtQuick.Controls 2.2

Window {
	id: root
	visible: true
	width: 480
	height: 272

	signal animationFinished()

	property var nextItemAnimation: true;
	property int  dur: 4000

	function changeScreen(msg, direction) {
		console.log("changing screen to: ", msg, direction)
		nextItemAnimation = direction
		stack.replace(stack.currentItem, msg/*, StackView.Immediate*/)
		return "Return value from changeScreen mainStack.qml method"
	}

	function goToBScreen() {
		console.log("calling goToBScreen() function ")
		nextItemAnimation = true
		stack.replace(stack.currentItem, screenBComponent /*, StackView.Immediate*/)
		return "Return value from changeScreen mainStack.qml method"
	}

	function goToComponentScreen(screenBComponent) {
		console.log("calling goToComponentScreen() function ")
		nextItemAnimation = true
		stack.replace(stack.currentItem, screenBComponent /*, StackView.Immediate*/)
		return "Return value from changeScreen mainStack.qml method"
	}

	Transition {
		id: nextItemEnterTransition
		XAnimator {
			from: (stack.mirrored ? -1 : 1) * stack.width
			to: 0
			duration: dur
			easing.type: Easing.OutCubic
		}
	}

	Transition {
		id: previousItemEnterTransition
		XAnimator {
			from: (stack.mirrored ? -1 : 1) * -stack.width
			to: 0
			duration: dur
			easing.type: Easing.OutCubic


		}
	}

	Transition {
		id: nextItemExitTransition
		XAnimator {
			from: 0
			to: (stack.mirrored ? -1 : 1) * -stack.width
			duration: dur
			easing.type: Easing.OutCubic
		}

		onRunningChanged:
		{
			console.log("onRunningChanged: ", running)
		}
	}

	Transition {
		id: previousItemExitTransition
		XAnimator {
			from: 0
			to: (stack.mirrored ? -1 : 1) * stack.width
			duration: dur
			easing.type: Easing.OutCubic
		}
	}

	StackView {
		id: stack
//		initialItem: Qt.resolvedUrl("ScreenA.qml")
		anchors.fill: parent

		replaceEnter: nextItemAnimation ? nextItemEnterTransition : previousItemEnterTransition

		replaceExit: nextItemAnimation ? nextItemExitTransition : previousItemExitTransition

		onReplaceEnterChanged:
		{
			console.log("onReplaceEnterChanged: ")
		}

		onBusyChanged:
		{
			console.log("Busy changed: ", busy)
			if (busy === false)
			{
				console.log("onStopped")
				root.animationFinished()
			}
		}

	}
}

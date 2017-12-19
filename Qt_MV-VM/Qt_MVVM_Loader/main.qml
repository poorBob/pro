import QtQuick 2.4
import QtQuick.Window 2.2

Window {
	id: root
	visible: true
	width: 480
	height: 272

	Loader {
		id: loader
		source: viewMgr.source
		asynchronous: true
//		visible: status == Loader.Ready
		onStatusChanged : {

//			status == Loader.Ready ? animation.running = true : animation.running = false
			status == Loader.Ready ? propAnimation.running = true : propAnimation.running = false
		}

		onLoaded:
		{
			console.log("Loader has loaded following screen: ", source)
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

	PropertyAnimation {
		id: propAnimation
		target: loader.item
		property: "x"
		from: target.width
		to: 0
		duration: 1000
		easing.type: Easing.OutCubic

		onStarted: { console.log("propAnimation started!") }
	}
}

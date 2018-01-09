#include "ViewManager.h"
#include <QDebug>
#include <QQmlEngine>
#include <QQmlContext>
#include <QQmlComponent>
#include <QQuickItem>

namespace
{
constexpr auto NEXT_ITEM_ANIMATION = true;
constexpr auto PREVIOUS_ITEM_ANIMATION = false;
}

ViewManager::ViewManager(QObject *parent) : QObject(parent)
{
	engine.rootContext()->setContextProperty("screenADataContext", &screenA_VM);



	QQmlComponent component(&engine, "qrc:/mainStack.qml");
	qDebug() << component.errors();
	mainView = component.create();

	QObject::connect(mainView, SIGNAL(animationFinished()),
	                 this, SLOT(cppSlot()));

	connect(&screenA_VM,SIGNAL(countDownFinished()), this, SLOT(goToScreenB()));
	connect(&screenB_VM,SIGNAL(countDownFinished()), this, SLOT(goToScreenA()));

	connect(&screenA_VM,SIGNAL(goToBClicked()), this, SLOT(goToScreenB()));
	connect(&screenB_VM,SIGNAL(goToAClicked()), this, SLOT(goToScreenA()));

	goToScreenA();
}

void ViewManager::goToScreenA()
{
	qDebug() << "ViewManager::goToScreenA()";
	engine.rootContext()->setContextProperty("screenADataContext", &screenA_VM);
	changeScreen("qrc:/ScreenA.qml", PREVIOUS_ITEM_ANIMATION);

	if (screenBItem != nullptr)
	{
//		qDebug() << "Deleteing the screenBItem! " << endl;
//		screenBItem->deleteLater();
//		delete screenBItem;
	}
}

void ViewManager::goToScreenB()
{
	qDebug() << "ViewManager::goToScreenB()" << screenBItem << ", " << screenBContext;
//	engine.rootContext()->setContextProperty("screenBDataContext", &screenB_VM);
//	changeScreen("qrc:/ScreenB.qml", NEXT_ITEM_ANIMATION);

	QQmlComponent component(&engine, "qrc:/ScreenB.qml");
	qDebug() << component.errors();
	screenBContext = new QQmlContext(engine.rootContext());
	screenBContext->setContextProperty("screenBDataContext", &screenB_VM);

	QObject *myObject = component.create(screenBContext);
	screenBItem = qobject_cast<QQuickItem*>(myObject);

//	engine.rootContext()->setContextProperty("screenBComponent", item);

	// this works:
	// QMetaObject::invokeMethod(mainView, "goToBScreen");

	QVariant v;
	v.setValue<QObject*>(screenBItem);
	QMetaObject::invokeMethod(mainView, "goToComponentScreen", Q_ARG(QVariant, v));
//	engine.setObjectOwnership(screenBItem, QQmlEngine::JavaScriptOwnership);

//	QVariant returnedValue;
//	QVariant newScr = "screenBComponent";


//	qDebug() << "has errors ? " << component.isError() << component.errors();
//	int width = item->width();  // width = 200
}

void ViewManager::changeScreen(const QString &screen, bool newItemAnimation)
{
	QVariant returnedValue;
	QVariant newScr = screen;
	QMetaObject::invokeMethod(mainView, "changeScreen",
	        Q_RETURN_ARG(QVariant, returnedValue),
	         Q_ARG(QVariant, newScr), Q_ARG(QVariant, newItemAnimation));

	//	qDebug() << "QML function returned:" << returnedValue.toString();
}

void ViewManager::cppSlot()
{
	qDebug() << "ViewManager::cppSlot()";
	if (screenBItem != nullptr)
	{
		qDebug() << "deleting the screenBItem";
		screenBItem->deleteLater();
		screenBItem = nullptr;
		screenBContext->deleteLater();
		screenBContext = nullptr;
	}
}


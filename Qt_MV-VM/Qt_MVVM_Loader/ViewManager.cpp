#include "ViewManager.h"
#include <QDebug>
#include <QQmlEngine>
#include <QQmlContext>
#include <QQmlComponent>

namespace
{
constexpr auto NEXT_ITEM_ANIMATION = true;
constexpr auto PREVIOUS_ITEM_ANIMATION = false;
}

ViewManager::ViewManager(QObject *parent) : QObject(parent)
{
	engine.rootContext()->setContextProperty("screenADataContext", &screenA_VM);

	QQmlComponent component(&engine, "qrc:/mainStack.qml");
	mainView = component.create();

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
}

void ViewManager::goToScreenB()
{
	qDebug() << "ViewManager::goToScreenB()";
	engine.rootContext()->setContextProperty("screenBDataContext", &screenB_VM);
	changeScreen("qrc:/ScreenB.qml", NEXT_ITEM_ANIMATION);
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


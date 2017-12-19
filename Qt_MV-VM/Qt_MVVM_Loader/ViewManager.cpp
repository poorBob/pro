#include "ViewManager.h"
#include <QDebug>
#include <QQmlEngine>
#include <QQmlContext>
#include <QQmlComponent>

ViewManager::ViewManager(QObject *parent) : QObject(parent)
{
	engine.rootContext()->setContextProperty("viewMgr", this);

	QQmlComponent component(&engine, "qrc:/mainStack.qml");
	mainView = component.create();

//	engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

	connect(&screenA_VM,SIGNAL(countDownFinished()), this, SLOT(goToScreenB()));
	connect(&screenB_VM,SIGNAL(countDownFinished()), this, SLOT(goToScreenA()));

	connect(&screenA_VM,SIGNAL(goToBClicked()), this, SLOT(goToScreenB()));

	goToScreenA();
}

void ViewManager::onNextClicked()
{
	qDebug() << "ViewManager::onNextClicked()" << endl;

	QVariant returnedValue;
	QVariant msg = "qrc:/ScreenA.qml";
	QMetaObject::invokeMethod(mainView, "myQmlFunction",
	        Q_RETURN_ARG(QVariant, returnedValue),
	         Q_ARG(QVariant, msg));

	qDebug() << "QML function returned:" << returnedValue.toString();

//	_source = "qrc:/ScreenA.qml";
//	emit sourceChanged();
}

void ViewManager::onPrevClicked()
{
	qDebug() << "ViewManager::onPrevClicked()" << endl;
	_source = "qrc:/ScreenB.qml";
	emit sourceChanged();
}

void ViewManager::goToScreenA()
{
	qDebug() << "ViewManager::goToScreenA()";

	engine.rootContext()->setContextProperty("vm", &screenA_VM);

	_source = screenA_VM.getSource();
	emit sourceChanged();
}

void ViewManager::goToScreenB()
{
	qDebug() << "ViewManager::goToScreenB()";

	engine.rootContext()->setContextProperty("vm", &screenB_VM);

	_source = screenB_VM.getSource();
	emit sourceChanged();

//	view.setSource(QUrl(QStringLiteral("qrc:/ScreenB.qml")));
}


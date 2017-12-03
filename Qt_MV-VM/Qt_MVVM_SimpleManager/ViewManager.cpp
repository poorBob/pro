#include "ViewManager.h"
#include <QDebug>
#include <QQmlEngine>
#include <QQmlContext>

ViewManager::ViewManager(QObject *parent) : QObject(parent)
{
	connect(&screenA_VM,SIGNAL(countDownFinished()), this, SLOT(goToScreenB()), Qt::QueuedConnection);
	connect(&screenB_VM,SIGNAL(countDownFinished()), this, SLOT(goToScreenA()), Qt::QueuedConnection);

	goToScreenA();
	view.show();
}

void ViewManager::goToScreenA()
{
	qDebug() << "ViewManager::goToScreenA()";

	view.engine()->rootContext()->setContextProperty("vm", &screenA_VM);
	view.setSource(QUrl(QStringLiteral("qrc:/ScreenA.qml")));
}

void ViewManager::goToScreenB()
{
	qDebug() << "ViewManager::goToScreenB()";

	view.engine()->rootContext()->setContextProperty("vm", &screenB_VM);
	view.setSource(QUrl(QStringLiteral("qrc:/ScreenB.qml")));
}

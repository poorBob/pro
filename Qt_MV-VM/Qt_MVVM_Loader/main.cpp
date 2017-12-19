#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include <QQuickItem>
#include <QQuickView>
#include <QDebug>
#include <QQmlProperty>

#include <QTimer>

#include "ViewManager.h"

int main(int argc, char *argv[])
{

	QGuiApplication app(argc, argv);
	ViewManager manago;

	return app.exec();
}

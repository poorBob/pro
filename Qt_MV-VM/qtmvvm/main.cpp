#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "RandomsModel.h"
#include "RandomsViewModel.h"
#include "RandomsFakeViewModel.h"

int main(int argc, char *argv[])
{
	QGuiApplication app(argc, argv);
	QQmlApplicationEngine engine;

	// Working solution
	RandomsModel rand;
	RandomsViewModel randVM(rand);
	engine.rootContext()->setContextProperty("randVM", &randVM);

	engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

	//test code:
//	RandomsFakeViewModel fakeRandVM;
//	engine.rootContext()->setContextProperty("randVM", &fakeRandVM);

	if (engine.rootObjects().isEmpty())
		return -1;

	return app.exec();
}


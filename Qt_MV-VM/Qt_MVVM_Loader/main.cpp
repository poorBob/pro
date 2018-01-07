#include <QGuiApplication>
#include "ViewManager.h"

int main(int argc, char *argv[])
{
	QGuiApplication app(argc, argv);
	ViewManager viemManager;

	return app.exec();
}

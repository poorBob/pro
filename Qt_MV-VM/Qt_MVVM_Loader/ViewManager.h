#ifndef VIEWMANAGER_H
#define VIEWMANAGER_H

#include <QObject>
#include <QQuickView>
#include <QQmlApplicationEngine>

#include "ScreenAViewModel.h"
#include "ScreenBViewModel.h"

class ViewManager : public QObject
{
	Q_OBJECT
public:
	explicit ViewManager(QObject *parent = nullptr);

public slots:
	void goToScreenA();
	void goToScreenB();

protected:
	void changeScreen(const QString & screen, bool newItemAnimation);

private slots:
	void cppSlot();

private:
	QObject * mainView{nullptr};

	QQmlContext * sceenBContext{nullptr};
	QQuickItem * screenBItem{nullptr};

	QQmlApplicationEngine engine;

	ScreenAViewModel screenA_VM;
	ScreenBViewModel screenB_VM;
};

#endif // VIEWMANAGER_H

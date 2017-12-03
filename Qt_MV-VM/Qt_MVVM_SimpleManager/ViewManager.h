#ifndef VIEWMANAGER_H
#define VIEWMANAGER_H

#include <QObject>
#include <QQuickView>

#include "ScreenAViewModel.h"
#include "ScreenBViewModel.h"

class ViewManager : public QObject
{
	Q_OBJECT
public:
	explicit ViewManager(QObject *parent = nullptr);

signals:

public slots:
	void goToScreenA();
	void goToScreenB();

private:
	QQuickView view;
	ScreenAViewModel screenA_VM;
	ScreenBViewModel screenB_VM;
};

#endif // VIEWMANAGER_H

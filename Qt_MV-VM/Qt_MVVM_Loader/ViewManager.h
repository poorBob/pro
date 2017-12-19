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
	Q_PROPERTY(QString source READ getSource /*WRITE setAlpha*/ NOTIFY sourceChanged)
public:
	explicit ViewManager(QObject *parent = nullptr);

	QString getSource() const {return _source;}

	Q_INVOKABLE void onNextClicked();
	Q_INVOKABLE void onPrevClicked();

signals:
	void sourceChanged();

public slots:
	void goToScreenA();
	void goToScreenB();

private:
	QString _source;
//	QQuickView view;
	QObject * mainView{nullptr};

	QQmlApplicationEngine engine;


	ScreenAViewModel screenA_VM;
	ScreenBViewModel screenB_VM;
};

#endif // VIEWMANAGER_H

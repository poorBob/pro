#ifndef SCREENBVIEWMODEL_H
#define SCREENBVIEWMODEL_H

#include <QObject>
#include "CounterModel.h"

class ScreenBViewModel : public QObject
{
	Q_OBJECT
	Q_PROPERTY(int clickLeft READ getClicksLeft /*WRITE setAlpha*/ NOTIFY clicksLeftChanged)
public:
	explicit ScreenBViewModel(QObject *parent = nullptr);

	Q_INVOKABLE void onCounterButtonClicked();
	Q_INVOKABLE void onGoToAButtonClicked();

	int getClicksLeft();

signals:
	void clicksLeftChanged();
	void countDownFinished();
	void goToAClicked();

public slots:


private:
	CounterModel _model;
};

#endif // SCREENBVIEWMODEL_H

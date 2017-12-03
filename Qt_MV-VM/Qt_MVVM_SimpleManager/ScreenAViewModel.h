#ifndef SCREENAVIEWMODEL_H
#define SCREENAVIEWMODEL_H

#include <QObject>
#include "CounterModel.h"

class ScreenAViewModel : public QObject
{
	Q_OBJECT
	Q_PROPERTY(int clickLeft READ getClicksLeft /*WRITE setAlpha*/ NOTIFY clicksLeftChanged)
public:
	explicit ScreenAViewModel(QObject *parent = nullptr);

	Q_INVOKABLE void onButtonClicked();

	int getClicksLeft();

signals:
	void clicksLeftChanged();
	void countDownFinished();

public slots:


private:
	CounterModel _model;
};


#endif // SCREENAVIEWMODEL_H

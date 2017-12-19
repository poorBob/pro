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

	QString getSource() const;

	Q_INVOKABLE void onButtonClicked();
	Q_INVOKABLE void onGoToBButtonClicked();

	int getClicksLeft();

signals:
	void clicksLeftChanged();
	void countDownFinished();

public slots:


private:
	CounterModel _model;
};

#endif // SCREENBVIEWMODEL_H

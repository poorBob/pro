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

	QString getSource() const;

	Q_INVOKABLE void onButtonClicked();
	Q_INVOKABLE void onGoToBButtonClicked();

	int getClicksLeft();

signals:
	void clicksLeftChanged();
	void countDownFinished();
	void goToBClicked();

public slots:


private:
	CounterModel _model;
};


#endif // SCREENAVIEWMODEL_H

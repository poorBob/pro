#include "ScreenBViewModel.h"
#include <QDebug>

ScreenBViewModel::ScreenBViewModel(QObject *parent) : QObject(parent)
{
	_model.setStartValue(5);
	connect(&_model, SIGNAL(valueChanged()), this, SIGNAL(clicksLeftChanged()));
	connect(&_model, SIGNAL(finished()), this, SIGNAL(countDownFinished()));
}

void ScreenBViewModel::onCounterButtonClicked()
{
	qDebug() << "ScreenBViewModel::onCounterButtonClicked()";
	_model.decrese();
}

void ScreenBViewModel::onGoToAButtonClicked()
{
	qDebug() << "ScreenBViewModel::onGoToAButtonClicked()";
	emit goToAClicked();
}

int ScreenBViewModel::getClicksLeft()
{
	return _model.getValue();
}

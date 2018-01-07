#include "ScreenAViewModel.h"
#include <QDebug>

ScreenAViewModel::ScreenAViewModel(QObject *parent) : QObject(parent)
{
	_model.setStartValue(7);
	connect(&_model, SIGNAL(valueChanged()), this, SIGNAL(clicksLeftChanged()));
	connect(&_model, SIGNAL(finished()), this, SIGNAL(countDownFinished()));
}

void ScreenAViewModel::onCounterButtonClicked()
{
	qDebug() << "ScreenAViewModel::onCounterButtonClicked()";
	_model.decrese();
}

void ScreenAViewModel::onGoToBButtonClicked()
{
	qDebug() << "ScreenAViewModel::onGoToBButtonClicked()";
	emit goToBClicked();
}

int ScreenAViewModel::getClicksLeft()
{
	return _model.getValue();
}

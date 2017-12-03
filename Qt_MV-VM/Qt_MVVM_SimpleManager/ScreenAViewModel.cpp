#include "ScreenAViewModel.h"
#include <QDebug>

ScreenAViewModel::ScreenAViewModel(QObject *parent) : QObject(parent)
{
	_model.setStartValue(7);
	connect(&_model, SIGNAL(valueChanged()), this, SIGNAL(clicksLeftChanged()));
	connect(&_model, SIGNAL(finished()), this, SIGNAL(countDownFinished()));
}

void ScreenAViewModel::onButtonClicked()
{
	qDebug() << "#### ScreenAViewModel::onButtonClicked()";
	_model.decrese();
}

int ScreenAViewModel::getClicksLeft()
{
	return _model.getValue();
}

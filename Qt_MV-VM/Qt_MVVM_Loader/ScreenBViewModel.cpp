#include "ScreenBViewModel.h"
#include <QDebug>

ScreenBViewModel::ScreenBViewModel(QObject *parent) : QObject(parent)
{
	_model.setStartValue(5);
	connect(&_model, SIGNAL(valueChanged()), this, SIGNAL(clicksLeftChanged()));
	connect(&_model, SIGNAL(finished()), this, SIGNAL(countDownFinished()));
}

QString ScreenBViewModel::getSource() const
{
	return QString("qrc:/ScreenB.qml");
}


void ScreenBViewModel::onButtonClicked()
{
	qDebug() << "#### ScreenBViewModel::onButtonClicked()";
	_model.decrese();
}

void ScreenBViewModel::onGoToBButtonClicked()
{
	qDebug() << "#### ScreenBViewModel::onGoToBButtonClicked()";
}

int ScreenBViewModel::getClicksLeft()
{
	return _model.getValue();
}

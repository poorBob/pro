#include "ScreenAViewModel.h"
#include <QDebug>

ScreenAViewModel::ScreenAViewModel(QObject *parent) : QObject(parent)
{
	_model.setStartValue(7);
	connect(&_model, SIGNAL(valueChanged()), this, SIGNAL(clicksLeftChanged()));
	connect(&_model, SIGNAL(finished()), this, SIGNAL(countDownFinished()));
}

QString ScreenAViewModel::getSource() const
{
	return QString("qrc:/ScreenA.qml");
}

void ScreenAViewModel::onButtonClicked()
{
	qDebug() << "#### ScreenAViewModel::onButtonClicked()";
	_model.decrese();
}

void ScreenAViewModel::onGoToBButtonClicked()
{
	emit goToBClicked();
}

int ScreenAViewModel::getClicksLeft()
{
	return _model.getValue();
}

#include "CounterModel.h"

CounterModel::CounterModel(QObject *parent) : QObject(parent)
{

}

void CounterModel::setStartValue(int startVal)
{
	_startVal = startVal;
	_val = _startVal;
}

int CounterModel::getValue() const
{
	return _val;
}

void CounterModel::decrese()
{
	_val--;
	if (_val > 0)
	{
	}
	else
	{
		_val = _startVal;
		emit finished();
	}

	emit valueChanged();
}

#ifndef COUNTERMODEL_H
#define COUNTERMODEL_H

#include <QObject>

class CounterModel : public QObject
{
	Q_OBJECT
public:
	explicit CounterModel(QObject *parent = nullptr);

	void setStartValue(int startVal);
	int getValue() const;

	void decrese();

signals:
	void valueChanged();
	void finished();		//emitted when _val = 0;

private:
	int _val;
	int _startVal;
};

#endif // COUNTERMODEL_H

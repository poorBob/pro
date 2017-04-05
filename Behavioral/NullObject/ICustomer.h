#ifndef ICUSTOMER_H
#define ICUSTOMER_H

#include <QString>

class ICustomer
{
public:
	ICustomer(const QString & name)
	    : m_name(name)
	{

	}
	virtual ~ICustomer() = default;

	virtual QString getName() const = 0;
	virtual bool isNull() const = 0;

protected:
	QString m_name;
};

#endif // ICUSTOMER_H

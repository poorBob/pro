#include "NullCustomer.h"

NullCustomer::NullCustomer(const QString &name)
    : ICustomer(name)
{

}

QString NullCustomer::getName() const
{
	return QString("Customer does not exist");
}

bool NullCustomer::isNull() const
{
	return true;
}

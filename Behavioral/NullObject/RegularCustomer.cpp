#include "RegularCustomer.h"

RegularCustomer::RegularCustomer(const QString &name)
    : ICustomer(name)
{

}

QString RegularCustomer::getName() const
{
	return m_name;
}

bool RegularCustomer::isNull() const
{
	return false;
}

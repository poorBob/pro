#include "CustomerFactory.h"

#include "RegularCustomer.h"
#include "NullCustomer.h"

CustomerFactory::CustomerFactory()
{
	m_customers = {"Alina", "Robert", "Bruno"};
}

std::unique_ptr<ICustomer> CustomerFactory::getCustomer(const QString & name)
{
	std::unique_ptr<ICustomer> customer;

	if (m_customers.contains(name))
	{
		customer = std::make_unique<RegularCustomer>(name);
	}
	else
	{
		customer = std::make_unique<NullCustomer>("");
	}

	return std::move(customer);
}

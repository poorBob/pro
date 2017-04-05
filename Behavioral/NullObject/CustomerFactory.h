#ifndef CUSTOMERFACTORY_H
#define CUSTOMERFACTORY_H

#include <QString>
#include <QList>

#include <memory>

class ICustomer;

class CustomerFactory
{
public:
	CustomerFactory();
	~CustomerFactory() = default;

	std::unique_ptr<ICustomer> getCustomer(const QString & name);

private:
	QList<QString> m_customers;
};

#endif // CUSTOMERFACTORY_H

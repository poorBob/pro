#ifndef NULLCUSTOMER_H
#define NULLCUSTOMER_H

#include "ICustomer.h"

class NullCustomer : public ICustomer
{
public:
	explicit NullCustomer(const QString & name);
	virtual ~NullCustomer() = default;

	QString getName() const override;
	bool isNull() const override;
};

#endif // NULLCUSTOMER_H

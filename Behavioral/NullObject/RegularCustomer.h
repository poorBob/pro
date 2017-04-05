#ifndef REGULARCUSTOMER_H
#define REGULARCUSTOMER_H

#include "ICustomer.h"

class RegularCustomer : public ICustomer
{
public:
	explicit RegularCustomer(const QString & name);
	virtual ~RegularCustomer() = default;

	QString getName() const override;
	bool isNull() const override;
};

#endif // REGULARCUSTOMER_H

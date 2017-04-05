#include "CustomerFactory.h"
#include <ICustomer.h>
#include <memory>
#include <iostream>
#include <QString>

// https://www.tutorialspoint.com/design_pattern/null_object_pattern.htm

int main(int argc, char *argv[])
{
	Q_UNUSED(argc)
	Q_UNUSED(argv)

	std::unique_ptr<CustomerFactory> factory = std::make_unique<CustomerFactory>();

	std::unique_ptr<ICustomer> customRobert = factory->getCustomer("Robert");
	std::unique_ptr<ICustomer> customRafal = factory->getCustomer("Rafal");

	std::cout << customRobert->getName().toStdString() << std::endl;
	std::cout << customRafal->getName().toStdString() << std::endl;

}

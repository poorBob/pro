#include "RandomsModel.h"
#include <QDebug>

RandomsModel::RandomsModel(QObject *parent) : QObject(parent)
{
	connect(&timerAlpha, SIGNAL(timeout()), this, SLOT(generateAlpha()));
	timerAlpha.start(1000);
	timerAlpha.setSingleShot(false);

	connect(&timerBeta, SIGNAL(timeout()), this, SLOT(generateBeta()));
	timerBeta.start(500);

	connect(&timerGamma, SIGNAL(timeout()), this, SLOT(generateGamma()));
	timerGamma.start(250);
}

int RandomsModel::getAlpha() const
{
	return randomAlpha;
}

int RandomsModel::getBeta() const
{
	return randomAlpha;
}

int RandomsModel::getGamma() const
{
	return randomGamma;
}

void RandomsModel::generateAlpha()
{
	randomAlpha = generate();
	emit alphaChanged();
}

void RandomsModel::generateBeta()
{
	randomBeta = generate();
	emit betaChanged();
}

void RandomsModel::generateGamma()
{
	randomGamma = generate();
	emit gammaChanged();
}

int RandomsModel::generate()
{
	int randomNumber{0};
	std::random_device r;

	std::default_random_engine e1(r());
	std::uniform_int_distribution<int> uniform_dist(1, 1000);
	randomNumber = uniform_dist(e1);

	return randomNumber;
}

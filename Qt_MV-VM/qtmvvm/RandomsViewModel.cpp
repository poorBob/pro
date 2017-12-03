#include "RandomsViewModel.h"

RandomsViewModel::RandomsViewModel(RandomsModel &model, QObject *parent)
    : QObject(parent), _model(model)
{
	connect(&_model, SIGNAL(alphaChanged()), this, SIGNAL(alphaChanged()));
	connect(&_model, SIGNAL(betaChanged()), this, SIGNAL(betaChanged()));
	connect(&_model, SIGNAL(gammaChanged()), this, SIGNAL(gammaChanged()));
}

int RandomsViewModel::getAlpha() const
{
	return _model.getAlpha();
}

int RandomsViewModel::getBeta() const
{
	return _model.getBeta();
}

int RandomsViewModel::getGamma() const
{
	return _model.getGamma();
}

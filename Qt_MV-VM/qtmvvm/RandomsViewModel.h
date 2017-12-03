#ifndef RANDOMSVIEWMODEL_H
#define RANDOMSVIEWMODEL_H

#include <QObject>
#include "RandomsModel.h"

class RandomsViewModel : public QObject
{
	Q_OBJECT
	Q_PROPERTY(int randomAlpha READ getAlpha /*WRITE setAlpha*/ NOTIFY alphaChanged)
	Q_PROPERTY(int randomBeta READ getBeta /*WRITE setAlpha*/ NOTIFY betaChanged)
	Q_PROPERTY(int randomGamma READ getGamma /*WRITE setAlpha*/ NOTIFY gammaChanged)

public:
	explicit RandomsViewModel(RandomsModel &model, QObject *parent = nullptr);

	int getAlpha() const;
	int getBeta() const;
	int getGamma() const;

signals:
	void alphaChanged();
	void betaChanged();
	void gammaChanged();

public slots:

private:
	RandomsModel & _model;
};

#endif // RANDOMSVIEWMODEL_H

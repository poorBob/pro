#ifndef RANDOMSMODEL_H
#define RANDOMSMODEL_H

#include <QObject>
#include <QTimer>

class RandomsModel : public QObject
{
	Q_OBJECT
public:
	explicit RandomsModel(QObject *parent = nullptr);

	int getAlpha() const;
	int getBeta() const;
	int getGamma() const;

signals:
	void alphaChanged();
	void betaChanged();
	void gammaChanged();

public slots:

private slots:
	void generateAlpha();
	void generateBeta();
	void generateGamma();

private:
	int generate();

	QTimer timerAlpha;
	QTimer timerBeta;
	QTimer timerGamma;

	int randomAlpha{0};
	int randomBeta{0};
	int randomGamma{0};
};

#endif // RANDOMSMODEL_H


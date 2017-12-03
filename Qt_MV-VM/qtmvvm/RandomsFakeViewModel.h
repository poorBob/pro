#ifndef RandomsFakeViewModel_H
#define RandomsFakeViewModel_H

#include <QObject>

class RandomsFakeViewModel : public QObject
{
	Q_OBJECT
	Q_PROPERTY(int randomAlpha READ getAlpha /*WRITE setAlpha*/ NOTIFY alphaChanged)
	Q_PROPERTY(int randomBeta READ getBeta /*WRITE setAlpha*/ NOTIFY betaChanged)
	Q_PROPERTY(int randomGamma READ getGamma /*WRITE setAlpha*/ NOTIFY gammaChanged)

public:
	explicit RandomsFakeViewModel(QObject *parent = nullptr);

	int getAlpha() const {return 1;}
	int getBeta() const {return 2;}
	int getGamma() const {return 3;}
signals:

	void alphaChanged();
	void betaChanged();
	void gammaChanged();

public slots:
};

#endif // RandomsFakeViewModel_H

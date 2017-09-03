#include <iostream>

#include "condiment.h"
#include "sugar.h"
#include "milk.h"

using namespace std;

template<typename Res>
static Res accu(std::function<Res()> call, std::function<Res()> next)
{
    if(next)
    {
        cout << "in template's accu if " << call() << ", " << next() << endl;
        return call() + next();
    }

    cout << "ending template accu " << endl;
    return call();
}

int main()
{
    cout << "Chain od responsablity:" << endl;

    Condiment condiments;
    condiments.description = bind(&accu<string>, &Milk::description, condiments.description);
    condiments.description = bind(&accu<string>, &Sugar::description, condiments.description);
//    condiments.description = bind(&accu<string>, &Milk::description, condiments.description);
//    condiments.description = bind(&accu<string>, &Sugar::description, condiments.description);

    condiments.price = bind(&accu<float>, &Sugar::price, condiments.price);
    condiments.price = bind(&accu<float>, &Sugar::price, condiments.price);
    condiments.price = bind(&accu<float>, &Milk::price, condiments.price);

    cout << "Condiments: " << condiments.description() << endl;
    cout << "Price: " << condiments.price() << endl;

    return 0;
}

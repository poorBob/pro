#ifndef CONDIMENT_H
#define CONDIMENT_H

#include <functional>
#include <string>

struct Condiment
{
    std::function<std::string()> description;
    std::function<float()> price;
};

#endif // CONDIMENT_H

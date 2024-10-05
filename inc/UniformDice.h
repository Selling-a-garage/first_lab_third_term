#ifndef UNIFORMDICE_H
#define UNIFORMDICE_H

#include "AbstractDice.h"
#include <random>
class UniformDice: public AbstractDice{
public:;
    UniformDice(unsigned max, unsigned seed);
    unsigned roll() override;
private:
    unsigned max;
    std::uniform_int_distribution<unsigned> dstr;
    std::default_random_engine reng;
};

#endif


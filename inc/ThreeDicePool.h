#ifndef THREEDICEPOOL_H
#define THREEDICEPOOL_H
#include "AbstractDice.h"
#include "UniformDice.h"

class ThreeDicePool: public AbstractDice{
public:
    ThreeDicePool(unsigned max, unsigned seed_1, unsigned seed_2, unsigned seed_3);
    unsigned roll() override;
private:
    UniformDice pt1, pt2, pt3;
};
#endif
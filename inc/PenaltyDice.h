#ifndef PENALTYDICE_H
#define PENALTYDICE_H
#include "AbstractDice.h"

class PenaltyDice : public AbstractDice {
public:
    PenaltyDice(AbstractDice& d);
    unsigned roll() override;
private:
    AbstractDice& d;
};

#endif
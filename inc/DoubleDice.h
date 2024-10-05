#ifndef DOUBLEDICE_H
#define DOUBLEDICE_H
#include "PenaltyDice.h"
#include "BonusDice.h"

class DoubleDice : public BonusDice, public PenaltyDice {
public:
    DoubleDice(AbstractDice& d);
    unsigned roll() override;
};

#endif
#ifndef DOUBLEGOODDICE_H
#define DOUBLEGOODDICE_H
#include "PenaltyDice.h"
#include "BonusDice.h"
#include "AbstractDice.h"

class DoubleGoodDice : public AbstractDice {
public:
    DoubleGoodDice(AbstractDice& DB, AbstractDice& PB);
    unsigned roll() override;
private:
    AbstractDice& BD;
    AbstractDice& PD;
};

#endif
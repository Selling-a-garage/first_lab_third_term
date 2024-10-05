#ifndef BONUSDICE_H
#define BONUSDICE_H
#include "AbstractDice.h"

class BonusDice : public AbstractDice {
public:
    BonusDice(AbstractDice& d);
    unsigned roll() override;
private:
    AbstractDice& d;
};

#endif
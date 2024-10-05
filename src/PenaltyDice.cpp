#include "../inc/PenaltyDice.h"

PenaltyDice::PenaltyDice(AbstractDice& d) : d(d) { }

unsigned PenaltyDice::roll() {
    unsigned roll1 = d.roll();
    unsigned roll2 = d.roll();
    return roll1<roll2 ? roll1 : roll2;
}
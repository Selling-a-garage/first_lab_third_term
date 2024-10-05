#include "../inc/DoubleDice.h"

DoubleDice::DoubleDice(AbstractDice& d) : BonusDice(d), PenaltyDice(d) { }

unsigned DoubleDice::roll(){
    return BonusDice::roll()+PenaltyDice::roll();
}

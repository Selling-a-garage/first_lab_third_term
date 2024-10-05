#include "../inc/DoubleGoodDice.h"

DoubleGoodDice::DoubleGoodDice(AbstractDice& DB, AbstractDice& PB) : BD(BD), PD(PD) { }

unsigned DoubleGoodDice::roll(){
    return BD.roll()+PD.roll();
}

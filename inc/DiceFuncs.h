#ifndef DICEFUNCS_H
#define DICEFUNCS_H
#include "AbstractDice.h"
#include "BonusDice.h"
#include "PenaltyDice.h"
#include "DoubleDice.h"

double expected_value(AbstractDice& d, unsigned number_of_rolls = 1);
double value_probability(unsigned value, AbstractDice& d, unsigned number_of_rolls = 1);
double expected_value(DoubleDice& d, unsigned number_of_rolls = 1);
double value_probability(unsigned value, DoubleDice& d, unsigned number_of_rolls = 1);

#endif
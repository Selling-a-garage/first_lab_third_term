#include "../inc/DiceFuncs.h"

double expected_value(AbstractDice& d, unsigned number_of_rolls) {
    unsigned long long accum = 0;
    for (unsigned cnt = 0; cnt < number_of_rolls; ++cnt)
        accum += d.roll(); 
    return static_cast<double>(accum) / static_cast<double>(number_of_rolls); 
}

double value_probability(unsigned value, AbstractDice& d, unsigned number_of_rolls){
    unsigned success_count = 0;
    for (unsigned i = 0; i < number_of_rolls; ++i) {
        if (d.roll() == value) {
            success_count++;
        }
    }
    return static_cast<double>(success_count) / static_cast<double>(number_of_rolls);
}

double expected_value(DoubleDice& d, unsigned number_of_rolls) {
    unsigned long long accum = 0;
    for (unsigned cnt = 0; cnt < number_of_rolls; ++cnt)
        accum += d.roll(); 
    return static_cast<double>(accum) / static_cast<double>(number_of_rolls); 
}

double value_probability(unsigned value, DoubleDice& d, unsigned number_of_rolls){
    unsigned success_count = 0;
    for (unsigned i = 0; i < number_of_rolls; ++i) {
        if (d.roll() == value) {
            success_count++;
        }
    }
    return static_cast<double>(success_count) / static_cast<double>(number_of_rolls);
}
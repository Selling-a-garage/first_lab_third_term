#include "../inc/UniformDice.h"

UniformDice::UniformDice(unsigned max, unsigned seed) : max(max), dstr(1, max), reng(seed) { }

unsigned UniformDice::roll() { 
        return dstr(reng);
}

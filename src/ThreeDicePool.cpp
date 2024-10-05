#include "../inc/ThreeDicePool.h"

ThreeDicePool::ThreeDicePool(unsigned max, unsigned seed_1, unsigned seed_2, unsigned seed_3) :
    pt1(max, seed_1), pt2(max, seed_2), pt3(max, seed_3) { }

unsigned ThreeDicePool::roll() {
    return pt1.roll()+pt2.roll()+pt3.roll();
}
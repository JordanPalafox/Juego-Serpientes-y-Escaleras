#include <iostream>
#include <random>
#include "dice.h"

using namespace std;

Dice::Dice() : generator(random_device()()), distribution(1, 6) {}

int Dice::roll() {
    return distribution(generator);
}
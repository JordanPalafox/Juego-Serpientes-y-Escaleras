#include <iostream>
#include <random>

using namespace std;

class Dice {
    private:
        mt19937 generator;
        uniform_int_distribution<int> distribution;

    public:
        Dice();
        int roll();
};

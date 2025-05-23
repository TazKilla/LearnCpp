// Random.h
#pragma once

#include <random>

using namespace std;

namespace Random {

    random_device seeder;
    unsigned int seed{seeder()};
    mt19937 engine{seeder()};

    void PrintSeed() {
        cout << "Seed: " << seed << endl;
    }

    void Reseed(unsigned int NewSeed) {
        seed = NewSeed;
        engine.seed(NewSeed);
    }

    int Int(int min, int max) {
        uniform_int_distribution get{min, max};
        return get(engine);
    }

    bool Bool(float probability) {
        uniform_real_distribution get{0.0, 1.0};
        return probability > get(engine);
    }
}
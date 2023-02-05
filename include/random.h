#ifndef RANDOM_H
#define RANDOM_H


#include <random>

namespace Random 
{
    static std::random_device rd;
	static std::seed_seq ss{ rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd() }; // get 8 integers of random numbers from std::random_device for our seed
	static std::mt19937 randomizer{ ss };
    static std::uniform_real_distribution<float> NCDrand{0.0f,1.0f};
    static std::uniform_int_distribution colorPicker{0,2};
}

#endif
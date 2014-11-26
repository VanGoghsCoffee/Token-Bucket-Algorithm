#include "RandomGenerator.h"
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Singleton implementation from http://gameprogrammingpatterns.com/singleton.html
CRandomGenerator& CRandomGenerator::instance()
{
    static CRandomGenerator *instance = new CRandomGenerator();
    return *instance;
}

double CRandomGenerator::uniform (double min, double max)
{
    return (double)random()/(double)(RAND_MAX)*(max-min) + min;
}

double CRandomGenerator::exponential(double mean)
{
    return -log(uniform(0,1))/mean;
}

CRandomGenerator::CRandomGenerator()
{
    // init random seed
    srand (time(NULL));
}

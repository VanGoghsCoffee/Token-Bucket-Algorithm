#ifndef _SKNS_RANDOMGENERATOR_H
#define _SKNS_RANDOMGENERATOR_H

class CRandomGenerator
{
    // Singleton (test reason, tried to use some patterns)
    public:
        static CRandomGenerator& instance();

    public:
        double uniform (double min, double max);
        double exponential(double mean);

    private:
        CRandomGenerator();
};

#endif /* _SKNS_RANDOMGENERATOR_H */

#ifndef DISTRIBUTION_H_INCLUDED
#define DISTRIBUTION_H_INCLUDED

#include "Random.h"
#include <math.h>
#include "eda/StatisticsIn.h"

class Distribution{

    private:
        Random random;

    public:
        Distribution(Random random);
        Distribution();
        Random getRandom();
        void setRandom(Random random);
        double uniform(double a, double b);
        double normal(double mu, double desv);
        double exponential(double lambda);
        double determineDistribution(string interarrive, double interarriveInter1, double interarriveInter2);

};

#endif // DISTRIBUTION_H_INCLUDED


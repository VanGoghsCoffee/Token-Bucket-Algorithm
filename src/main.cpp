#include <iostream>
#include "RandomGenerator.h"
#include "TokenGenerator.h"
#include "PacketGenerator.h"
#include "Bucket.h"
#include "TokenBucketSimulation.h"

int main()
{
    CTokenBucketSimulation* simulation = new CTokenBucketSimulation();

    // setting simulation params
    simulation->setBucketMaxSize(30000);
    simulation->setBucketStartSize(1000);
    simulation->setBucketStepSize(500);
    simulation->setMeanPacketRate(1250);
    simulation->setRounds(100);
    simulation->setBitrate(8000000);
    simulation->setSimulationTime(10);

    simulation->run();

    delete simulation;


    return 0;
}

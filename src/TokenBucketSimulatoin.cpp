#include <iostream>
#include "TokenBucketSimulation.h"
#include "Bucket.h"
#include "Statistics.h"

CTokenBucketSimulation::CTokenBucketSimulation(int _BucketStartSize, int _BucketMaxSize, int _BucketStepSize, int _SimulationTime, int _MeanPacketRate, int _Bitrate, int _Rounds)
    : m_BucketStartSize(_BucketStartSize)
    , m_BucketMaxSize  (_BucketMaxSize)
    , m_BucketStepSize (_BucketStepSize)
    , m_SimulationTime (_SimulationTime)
    , m_MeanPacketRate (_MeanPacketRate)
    , m_Bitrate        (_Bitrate)
    , m_Rounds         (_Rounds)
{
}

CTokenBucketSimulation::CTokenBucketSimulation()
{
}

// runs the simulation
void CTokenBucketSimulation::run()
{
    int nonConPcks      = 0;
    float ncRate        = 0.f;
    int PacketNumber    = m_SimulationTime * m_MeanPacketRate;

    // Creates statistics with (m_BucketMaxSize - m_BucketStartSize) / m_BucketStepSize entries
    // -> maxSize = 30000, startSize = 1000, stepSize = 500 --> 58 entries
    CStatistics* statistics = new CStatistics((m_BucketMaxSize - m_BucketStartSize) / m_BucketStepSize);

    for (int bucketSize = m_BucketStartSize; bucketSize < m_BucketMaxSize; bucketSize += m_BucketStepSize)
    {
        CBucket* tokenBucket = new CBucket(bucketSize);
        for (int round = 0; round < m_Rounds; ++round)
        {
            for (int packet = 0; packet < PacketNumber; ++packet)
            {
                tokenBucket->stress(m_Bitrate, m_MeanPacketRate);
            }
        }
        nonConPcks = tokenBucket->getNonConformalPackets();
        ncRate     = (float)nonConPcks / (float)(PacketNumber * m_Rounds);

        std::cout << "NonConRate: " << ncRate << std::endl;
        // Write statistics for current bucket size
        statistics->addStatistics(bucketSize, m_Rounds, m_SimulationTime, nonConPcks, ncRate);

        delete tokenBucket;
    }
    statistics->writeToFile();

    delete statistics;
}

// Sets the maximum Bucket size
void CTokenBucketSimulation::setBucketMaxSize(int _BucketMaxSize)
{
    m_BucketMaxSize = _BucketMaxSize;
}

// Sets the start size of the bucket
void CTokenBucketSimulation::setBucketStartSize(int _BucketStartSize)
{
    m_BucketStartSize = _BucketStartSize;
}

// Sets the step size with which the bucket shall increase
void CTokenBucketSimulation::setBucketStepSize(int _BucketStepSize)
{
    m_BucketStepSize = _BucketStepSize;
}

// Sets the mean packet rate
void CTokenBucketSimulation::setMeanPacketRate(int _MeanPacketRate)
{
    m_MeanPacketRate = _MeanPacketRate;
}

// Sets the simulation time
void CTokenBucketSimulation::setSimulationTime(int _SimulationTime)
{
    m_SimulationTime = _SimulationTime;
}

// Sets the simulation bitrate
void CTokenBucketSimulation::setBitrate(int _Bitrate)
{
    m_Bitrate = _Bitrate;
}

// Sets the round count for the simulation
void CTokenBucketSimulation::setRounds(int _Rounds)
{
    m_Rounds = _Rounds;
}

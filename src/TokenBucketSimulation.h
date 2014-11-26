#ifndef __SKNS_TOKENBUCKETSIMULATION_H
#define __SKNS_TOKENBUCKETSIMULATION_H

class CTokenBucketSimulation
{
    public:
        CTokenBucketSimulation();
        CTokenBucketSimulation(int _BucketStartSize, int _BucketMaxSize, int _BucketStepSize, int _SimulationTime, int _MeanPacketRate, int _Bitrate, int _Rounds);

    public:
        void run();

    public:
        void setBucketStartSize(int _BucketStartSize);
        void setBucketMaxSize(int _BucketMaxSize);
        void setBucketStepSize(int _BucketStepSize);
        void setSimulationTime(int _SimulationTime);
        void setMeanPacketRate(int _MeanPacketRate);
        void setBitrate(int _Bitrate);
        void setRounds(int _Rounds);

    private:
        int m_BucketStartSize;
        int m_BucketMaxSize;
        int m_BucketStepSize;
        int m_SimulationTime;
        int m_MeanPacketRate;
        int m_Bitrate;
        int m_Rounds;
};

#endif /* __SKNS_TOKENBUCKETSIMULATION_H */

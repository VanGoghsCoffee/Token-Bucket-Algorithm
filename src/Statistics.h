#ifndef __SKNS_STATISTICS_H
#define __SKNS_STATISTICS_H

#include <string>

class CStatistics
{
    public:
        CStatistics(int _Size);
        ~CStatistics();

    public:
        void addStatistics(int _BucketSize, int _Rounds, int _Seconds, int _NonConformal, float _NcRate);
        void writeToFile();

    private:
    float** m_Statistics;
    int   m_StatSize;
    int   m_StatPosition;

};

#endif /* __SKNS_STATISTICS_H */

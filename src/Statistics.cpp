#include <fstream>
#include <iostream>

#include "Statistics.h"


CStatistics::CStatistics(int _Size)
    : m_StatSize    (_Size)
    , m_StatPosition(0)
{
    m_Statistics = new float*[_Size];
    for (int i = 0; i < _Size; ++i)
    {
        m_Statistics[i] = new float[5];
    }
}

CStatistics::~CStatistics()
{
    delete[] m_Statistics;
}

void CStatistics::addStatistics(int _BucketSize, int _Rounds, int _Seconds, int _NonConformal, float _NcRate)
{
    m_Statistics[m_StatPosition][0] = (float) _BucketSize;
    m_Statistics[m_StatPosition][1] = (float) _Rounds;
    m_Statistics[m_StatPosition][2] = (float) _Seconds;
    m_Statistics[m_StatPosition][3] = (float) _NonConformal;
    m_Statistics[m_StatPosition][4] = (float) _NcRate;

    ++m_StatPosition;
}

void CStatistics::writeToFile()
{
    std::ofstream statFile;
    statFile.open("TokenBucketAnalysis.csv");

    statFile << "Bucketsize,Rounds,Seconds,Non-Conformal Pcks,Non-Conformal Rate" << "\n";

    for (int i = 0; i < m_StatSize; ++i)
    {
        statFile << m_Statistics[i][0] << ","
                 << m_Statistics[i][1] << ","
                 << m_Statistics[i][2] << ","
                 << m_Statistics[i][3] << ","
                 << m_Statistics[i][4] << "\n";
    }

    statFile.close();
}



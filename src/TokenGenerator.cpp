#include "TokenGenerator.h"
#include "RandomGenerator.h"
#include "PacketGenerator.h"
#include <iostream>

CTokenGenerator& CTokenGenerator::instance()
{
    static CTokenGenerator *instance = new CTokenGenerator();
    return *instance;
}

int CTokenGenerator::generateTokens(int _Bitrate, int _MeanPacketRate)
{
    double time = CRandomGenerator::instance().exponential(_MeanPacketRate);
    return time * _Bitrate / 8;
}

#ifndef _SKNS_TOKENGENERATOR_H
#define _SKNS_TOKENGENERATOR_H

class CTokenGenerator
{
    public:
        static CTokenGenerator& instance(); // singleton

    public:
        int generateTokens(int _Bitrate, int _MeanPacketRate);

    private:
        int m_MaxTokens;
};

#endif /* _SKNS_TOKENGENERATOR_H */

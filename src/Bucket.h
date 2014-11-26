#ifndef _SKNS_BUCKET_H
#define _SKNS_BUCKET_H

class CBucket
{
    public:
    CBucket(int _BucketSize);

    public:
    void addTokens(int _Tokens);
    int getTokens();
    void clearBucket();
    int getNonConformalPackets();

    void stress(int _Bitrate, int _MeanPacketRate);  // expose bucket to packets

    private:
        void addNonConformalPacket(int _Count);

    private:
    int m_BucketSize;
    int m_Tokens;
    int m_NonConPck;
};

#endif /* _SKNS_BUCKET_H */

#include "Bucket.h"
#include "PacketGenerator.h"
#include "TokenGenerator.h"
#include "Packet.h"

// init bucket with its max size
CBucket::CBucket(int _BucketSize)
    : m_BucketSize  (_BucketSize)
    , m_NonConPck   (0)
{
}

// adding tokens to bucket
void CBucket::addTokens(int _Tokens)
{
    if (_Tokens + m_Tokens > m_BucketSize)
    {
        m_Tokens = m_BucketSize;
    }
    else
    {
        m_Tokens += _Tokens;
    }
}

// read tokens from bucket
int CBucket::getTokens()
{
    return m_Tokens;
}

// clear tokens from bucket
void CBucket::clearBucket()
{
    m_Tokens = 0;
}

// getting non conformal packets
int CBucket::getNonConformalPackets()
{
    return m_NonConPck;
}

// expose bucket to packets
void CBucket::stress(int _Bitrate, int _MeanPacketRate)
{
    CPacketGenerator packetGenerator = CPacketGenerator::instance();
    CTokenGenerator tokenGenerator   = CTokenGenerator::instance();

    CPacket* packet = packetGenerator.generatePacket();


    // Generate tokens and add them to the bucket
    // If there are more tokens generated than the bucket can hold,
    // the spilled tokens will get lost
    addTokens(tokenGenerator.generateTokens(_Bitrate, _MeanPacketRate));
    if (m_Tokens > m_BucketSize)
    {
        m_Tokens = m_BucketSize;
    }

    // checks whether enough tokens are in the bucket to serve the
    // packet. If so, the bucket loses tokens in count of the packet-
    // length. If there are to less, a non-conformal packet is added.
    if (m_Tokens > packet->getPacketSize())
    {
        m_Tokens -= packet->getPacketSize();
    }
    else
    {
        addNonConformalPacket(1);
    }

    delete packet;
}

// adding lost packets
void CBucket::addNonConformalPacket(int _Count)
{
    m_NonConPck += _Count;
}

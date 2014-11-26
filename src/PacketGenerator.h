#ifndef _SKNS_PACKETGENERATOR_H
#define _SKNS_PACKETGENERATOR_H

// emulating CPacket, so I don't have to load the
// header
class CPacket;

class CPacketGenerator
{
    public:
        static const int MEAN_PACKETRATE        = 1250;
        static const int PACKET_LENGTH_START    = 100;
        static const int PACKET_LENGTH_END      = 1500;

    public:
        static CPacketGenerator& instance(); // singleton

    public:
        CPacket* generatePacket();
};

#endif /* _SKNS_PACKETGENERATOR_H */

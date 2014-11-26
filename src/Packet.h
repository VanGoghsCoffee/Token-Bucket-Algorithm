#ifndef _SKNS_PACKET_H
#define _SKNS_PACKET_H

class CPacket
{
    public:
    CPacket(int _PacketSize);

    public:
    int getPacketSize();

    private:
    int m_PacketSize;
};

#endif /* _SKNS_PACKET_H */

#include "Packet.h"

CPacket::CPacket(int _PacketSize)
{
    m_PacketSize = _PacketSize;
}

int CPacket::getPacketSize()
{
    return m_PacketSize;
}

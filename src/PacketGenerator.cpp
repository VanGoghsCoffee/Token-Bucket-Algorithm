#include "PacketGenerator.h"
#include "RandomGenerator.h"
#include "Packet.h"

CPacketGenerator& CPacketGenerator::instance()
{
    static CPacketGenerator *instance = new CPacketGenerator();
    return *instance;
}

CPacket* CPacketGenerator::generatePacket()
{
    CRandomGenerator randomGen = CRandomGenerator::instance();

    int length = (int)randomGen.uniform(PACKET_LENGTH_START, PACKET_LENGTH_END);

    return new CPacket(length);
}

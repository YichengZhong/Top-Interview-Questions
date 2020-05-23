#include "StrongPasswordSocre.h"

StrongPasswordSocre::StrongPasswordSocre(std::string Password, int ConsumptionSocre, int GainSocre, int NetSocre)
{
    m_Password = Password;
    m_ConsumptionSocre = ConsumptionSocre;
    m_GainSocre = GainSocre;
    m_NetSocre = NetSocre;
}

void StrongPasswordSocre::setConsumptionSocre(int ConsumptionSocre)
{
    m_ConsumptionSocre = ConsumptionSocre;
}

void StrongPasswordSocre::setGainSocre(int GainSocre)
{
    m_GainSocre = GainSocre;
}

void StrongPasswordSocre::setNetSocre(int NetSocre)
{
    m_NetSocre = NetSocre;
}

int StrongPasswordSocre::getConsumptionSocre()
{
    return m_ConsumptionSocre;
}

int StrongPasswordSocre::getNetSocre()
{
    return m_NetSocre;
}

int StrongPasswordSocre::getGainSocre()
{
    return m_GainSocre;
}

std::string StrongPasswordSocre::getPassword()
{
    return m_Password;
}

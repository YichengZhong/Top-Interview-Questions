#pragma once
#include <string>
class StrongPasswordSocre
{
public:
	StrongPasswordSocre(std::string Password, int ConsumptionSocre, int GainSocre, int NetSocre);

	void setConsumptionSocre(int ConsumptionSocre);

	void setGainSocre(int GainSocre);

	void setNetSocre(int NetSocre);

	int getConsumptionSocre();

	int getGainSocre();

	int getNetSocre();

	std::string getPassword();

	static bool selfcmp(StrongPasswordSocre a, StrongPasswordSocre b)
	{
		if (a.getNetSocre() > b.getNetSocre())
		{
			return true;
		}
		else if (a.getNetSocre() < b.getNetSocre())
		{
			return false;
		}
		else
		{
			return a.getConsumptionSocre() < b.getConsumptionSocre();
		}
	}

private:
	std::string m_Password;
	int m_ConsumptionSocre; //消耗积分
	int m_GainSocre; //赚取积分
	int m_NetSocre;	//净积分
};


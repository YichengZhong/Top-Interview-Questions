#include "ReadJson.h"

ReadJson::ReadJson(const char str_json[])
{
	v_StrongPasswordSocre.clear();
	PasswordNums = 0;
	PasswordMS = 0;

	if (NULL == str_json)
	{
		Password_json = NULL;
	}
	else
	{
		Password_json = cJSON_Parse(str_json);   //����JSON�������󣬷���JSON��ʽ�Ƿ���ȷ
	}
}

ReadJson::~ReadJson()
{
	if (Password_json != NULL)
	{
		cJSON_Delete(Password_json);//�ͷ��ڴ�
	}
}

void ReadJson::getPasswordInfo()
{
	std::vector<std::string>v_Password;
	std::vector<int>v_PasswordSocre;

	v_Password.clear();
	v_PasswordSocre.clear();

	getPasswordList(v_Password);
	getPasswordSocreList(v_PasswordSocre);

	if (v_Password.size() != v_PasswordSocre.size() || Password_json==NULL)
	{
		std::cout << "json��ʽ�쳣" << std::endl;
		return;
	}

	DealStrongPassword myDealStrongPassword;
	for (int i = 0; i < v_Password.size(); ++i)
	{
		StrongPasswordSocre temp(v_Password[i], 0, v_PasswordSocre[i], 0);
		temp.setConsumptionSocre(myDealStrongPassword.strongPasswordChecker(temp.getPassword()));
		int net = temp.getGainSocre() - temp.getConsumptionSocre();
		temp.setNetSocre(net);
		v_StrongPasswordSocre.push_back(temp);
	}

	cJSON *str_PasswordNums = cJSON_GetObjectItem(Password_json, "N");   //��ȡN����Ӧ��ֵ����Ϣ
	if (str_PasswordNums->type == cJSON_Number)
	{
		PasswordNums = str_PasswordNums->valueint;
	}

	cJSON *str_PasswordMS = cJSON_GetObjectItem(Password_json, "MS");   //��ȡMS����Ӧ��ֵ����Ϣ
	if (str_PasswordMS->type == cJSON_Number)
	{
		PasswordMS = str_PasswordMS->valueint;
	}
}

void ReadJson::getPasswordList(std::vector<std::string>&v_Password)
{
	cJSON *str_PasswordList = cJSON_GetObjectItem(Password_json, "P"); //��ȡP����Ӧ��ֵ����Ϣ

	if (str_PasswordList != NULL)
	{
		int  array_size = cJSON_GetArraySize(str_PasswordList);

		for (int iCnt = 0; iCnt < array_size; iCnt++)
		{
			cJSON * pSub = cJSON_GetArrayItem(str_PasswordList, iCnt);
			if (NULL == pSub)
			{
				continue;
			}

			char * ivalue = pSub->valuestring;
			v_Password.push_back(ivalue);
			printf("str_PasswordList[%d] : %s\n", iCnt, ivalue);
		}
	}
	else
	{
		std::cout << "json��ʽ�쳣" << std::endl;
	}
}

void ReadJson::getPasswordSocreList(std::vector<int>&v_PasswordSocre)
{
	cJSON *str_PasswordSocreList = cJSON_GetObjectItem(Password_json, "C"); //��ȡC����Ӧ��ֵ����Ϣ
	if (str_PasswordSocreList != NULL)
	{
		int  array_size = cJSON_GetArraySize(str_PasswordSocreList);

		for (int iCnt = 0; iCnt < array_size; iCnt++)
		{
			cJSON * pSub = cJSON_GetArrayItem(str_PasswordSocreList, iCnt);
			if (NULL == pSub)
			{
				continue;
			}

			int  ivalue = pSub->valueint;
			v_PasswordSocre.push_back(ivalue);
			printf("str_PasswordSocreList[%d] : %d\n", iCnt, ivalue);
		}
	}
	else
	{
		std::cout << "json��ʽ�쳣" << std::endl;
	}
}

std::vector<StrongPasswordSocre> ReadJson::getStrongPasswordList()
{
	return v_StrongPasswordSocre;
}

int ReadJson::getPasswordNums()
{
	return PasswordNums;
}

int ReadJson::getPasswordMS()
{
	return PasswordMS;
}

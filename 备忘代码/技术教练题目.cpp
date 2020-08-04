#include <vector>
#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <sstream>
#include "cJSON.h"

int MS=0;

class StrongPasswordSocre
{
public:
    StrongPasswordSocre(std::string Password, int ConsumptionSocre, int GainSocre, int NetSocre)
    {
        m_Password = Password;
        m_ConsumptionSocre = ConsumptionSocre;
        m_GainSocre = GainSocre;
        m_NetSocre = NetSocre;
    }

    void setConsumptionSocre(int ConsumptionSocre)
    {
        m_ConsumptionSocre = ConsumptionSocre;
    }

    void setGainSocre(int GainSocre)
    {
        m_GainSocre = GainSocre;
    }

    void setNetSocre(int NetSocre)
    {
        m_NetSocre = NetSocre;
    }

    int getConsumptionSocre()
    {
        return m_ConsumptionSocre;
    }

    int getGainSocre()
    {
        return m_GainSocre;
    }

    int getNetSocre()
    {
        return m_NetSocre;
    }

    std::string getPassword()
    {
        return m_Password;
    }

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
    int m_NetSocre; //净积分
};


class DealStrongPassword 
{
public:
    int strongPasswordChecker(std::string s) 
    {
        int res = 0;
        int n = s.size();
        int lower = 1;
        int upper = 1;
        int digit = 1;
        std::vector<int> v(n, 0);
        for (int i = 0; i < n;) 
        {
            if (s[i] >= 'a' && s[i] <= 'z')
            {
                lower = 0;
            }
            if (s[i] >= 'A' && s[i] <= 'Z')
            {
                upper = 0;
            }
            if (s[i] >= '0' && s[i] <= '9')
            {
                digit = 0;
            }
            int j = i;
            while (i < n && s[i] == s[j])
            {
                ++i;
            }
                
            v[j] = i - j;
        }
        int missing = (lower + upper + digit);
        if (n < 6)
        {
            int diff = 6 - n;
            res = std::max(diff, missing);
        }
        else if (n > 20)
        {
            int over = std::max(n - 20, 0), left = 0;
            res += over;
            for (int k = 1; k < 3; ++k)
            {
                for (int i = 0; i < n && over >= k; ++i)
                {
                    if (v[i] < 3 || v[i] % 3 != (k - 1)) 
                        continue;
                    v[i] -= k;
                    over -= k;
                }
            }
            for (int i = 0; i < n; ++i)
            {
                if (v[i] >= 3 && over > 0)
                {
                    int need = v[i] - 2;
                    v[i] -= over;
                    over -= need;
                }
                if (v[i] >= 3)
                {
                    left += v[i] / 3;
                }
                    
            }
            res += std::max(missing, left);
        }
        else
        {
            int link = 0;
            for (int i = v.size() - 1; i >= 0; i--)
            {
                if (v[i] >= 3)
                {
                    link += v[i] / 3;
                }
                    
            }
                
            res = std::max(missing, link);
        }

        return res;
    }
};

//例子：{\"P\":[\"123456\",\"abcdEF\"],\"C\":[3,2],\"N\":2,\"MS\":1}

class ReadJson
{
public:
    ReadJson(char str_json[])
    {
        v_StrongPasswordSocre.clear();
        PasswordNums=0;
        PasswordMS=0;

        if (NULL == str_json)
        {
            Password_json=NULL;
        }
        else
        {
            Password_json = cJSON_Parse(str_json);   //创建JSON解析对象，返回JSON格式是否正确
        }        
    }

    ~ReadJson()
    {
        if (Password_json != NULL)
        {
            cJSON_Delete(Password_json);//释放内存
        }
    }

    void getPasswordInfo()
    {
        std::vector<std::string>v_Password;
        std::vector<int>v_PasswordSocre;

        v_Password.clear();
        v_PasswordSocre.clear();

        getPasswordList(v_Password);
        getPasswordSocreList(v_PasswordSocre);

        if (v_Password.size() != v_PasswordSocre.size())
        {
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

        cJSON *str_PasswordNums = cJSON_GetObjectItem(Password_json, "N");   //获取N键对应的值的信息
        if (str_PasswordNums->type == cJSON_Number)
        {
            PasswordNums = str_PasswordNums->valueint;
        }

        cJSON *str_PasswordMS = cJSON_GetObjectItem(Password_json, "MS");   //获取MS键对应的值的信息
        if (str_PasswordMS->type == cJSON_Number)
        {
            PasswordMS = str_PasswordMS->valueint;
        }
    }

    void getPasswordList(std::vector<std::string>&v_Password)
    {
        cJSON *str_PasswordList = cJSON_GetObjectItem(Password_json, "P"); //获取P键对应的值的信息

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
    }

    void getPasswordSocreList(std::vector<int>&v_PasswordSocre)
    {
        cJSON *str_PasswordSocreList = cJSON_GetObjectItem(Password_json, "C"); //获取C键对应的值的信息
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
    }

    std::vector<StrongPasswordSocre> getStrongPasswordList()
    {
        return v_StrongPasswordSocre;
    }

    int getPasswordNums()
    {
        return PasswordNums;
    }

    int getPasswordMS()
    {
        return PasswordMS;
    }

private:
    std::vector<StrongPasswordSocre>v_StrongPasswordSocre;
    int PasswordNums;
    int PasswordMS;
    cJSON *Password_json;
};


//计算最终结果
void CalculateMS(std::vector<StrongPasswordSocre>v_StrongPasswordSocreVector,int PasswordNums,int PasswordMS)
{
    if (v_StrongPasswordSocreVector.size() == 0)
    {
        std::cout << PasswordMS << "-" << 0 << std::endl;
        return;
    }

    std::sort(v_StrongPasswordSocreVector.begin(), v_StrongPasswordSocreVector.end(), StrongPasswordSocre::selfcmp);

    int outPasswordNums = 0, outPasswordMS = PasswordMS;

    int outPasswordCheckNums = 0;
    for (int i = 0; i < v_StrongPasswordSocreVector.size(); ++i)
    {
        if (i < PasswordNums && v_StrongPasswordSocreVector[i].getNetSocre() > 0)
        {
            outPasswordMS = outPasswordMS + v_StrongPasswordSocreVector[i].getNetSocre();
            outPasswordCheckNums++;
        }
        else
        {
            break;
        }
    }

    std::cout << outPasswordMS << "-" << outPasswordCheckNums << std::endl;
}

void test1()
{
    StrongPasswordSocre temp1("123456",0,3,0);
    StrongPasswordSocre temp2("abcdEF",0,2,0);
    StrongPasswordSocre temp3("ab1dEF", 0, 2, 0);

    DealStrongPassword myDealStrongPassword;
    int net = 0;

    temp1.setConsumptionSocre(myDealStrongPassword.strongPasswordChecker(temp1.getPassword()));
    net = temp1.getGainSocre() - temp1.getConsumptionSocre();
    temp1.setNetSocre(net);

    temp2.setConsumptionSocre(myDealStrongPassword.strongPasswordChecker(temp2.getPassword()));
    net = temp2.getGainSocre() - temp2.getConsumptionSocre();
    temp2.setNetSocre(net);

    temp3.setConsumptionSocre(myDealStrongPassword.strongPasswordChecker(temp3.getPassword()));
    net = temp3.getGainSocre() - temp3.getConsumptionSocre();
    temp3.setNetSocre(net);

    std::vector<StrongPasswordSocre>v_StrongPasswordSocreVector;
    v_StrongPasswordSocreVector.clear();

    v_StrongPasswordSocreVector.push_back(temp1);
    v_StrongPasswordSocreVector.push_back(temp2);
    v_StrongPasswordSocreVector.push_back(temp3);

    CalculateMS(v_StrongPasswordSocreVector, 2, 1);
}

void test2()
{
    char str_json[] = "{\"P\":[\"123456\",\"abcdEF\"],\"C\":[3,2],\"N\":2,\"MS\":1}";
    ReadJson myReadJson(str_json);
    myReadJson.getPasswordInfo();

    std::vector<StrongPasswordSocre>v_StrongPasswordSocreVector;
    v_StrongPasswordSocreVector.clear();
    v_StrongPasswordSocreVector = myReadJson.getStrongPasswordList();
    int PasswordNums= myReadJson.getPasswordNums();
    int PasswordMS = myReadJson.getPasswordMS();

    CalculateMS(v_StrongPasswordSocreVector, PasswordNums, PasswordMS);
}

int main()
{
    //test1();
    test2();
    return 0;
}
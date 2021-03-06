#include <vector>
#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector>
#include "StrongPasswordSocre.h"
#include "StrongPasswordCheck.h"
#include "ReadJson.h"
#include "json.hpp"
#include <fstream>
#include <sstream>
using json = nlohmann::json;

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
    for (int i = 0; i < std::min((int)v_StrongPasswordSocreVector.size(), PasswordNums); ++i)
    {
        if (v_StrongPasswordSocreVector[i].getNetSocre() > 0)
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
    StrongPasswordSocre temp1("!@#",0,3,0);
    StrongPasswordSocre temp2("abcdEF",0,2,0);
    StrongPasswordSocre temp3("ab1dEF", 0, 2, 0);

    StrongPasswordCheck myDealStrongPassword;
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
    std::ifstream InJsonFile("file.json"); //可以读取txt、json等文件

    if (!InJsonFile.is_open())
    {
        std::cout << "文件打开失败！" << std::endl;
    }

    std::string str((std::istreambuf_iterator<char>(InJsonFile)),std::istreambuf_iterator<char>());
    std::cout << str << std::endl;

    //char str_json[] = "{\"P\":[\"123456\",\"abcdEF\"],\"C\":[3,2],\"N\":2,\"MS\":1}";
    const char *str_json = str.c_str();
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
    //test3();
    //test4();
    return 0;
}
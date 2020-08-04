#pragma once
#include "cJSON.h"
#include "StrongPasswordSocre.h"
#include "StrongPasswordCheck.h"
#include <vector>
#include <iostream>

//Р§згЃК{\"P\":[\"123456\",\"abcdEF\"],\"C\":[3,2],\"N\":2,\"MS\":1}
class ReadJson
{
public:
    ReadJson(const char str_json[]);

    ~ReadJson();

    void getPasswordInfo();
    
    void getPasswordList(std::vector<std::string>&v_Password);

    void getPasswordSocreList(std::vector<int>&v_PasswordSocre);

    std::vector<StrongPasswordSocre> getStrongPasswordList();

    int getPasswordNums();

    int getPasswordMS();

private:
    std::vector<StrongPasswordSocre>v_StrongPasswordSocre;
    int PasswordNums;
    int PasswordMS;
    cJSON *Password_json;
};

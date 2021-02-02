#include "UserData.h"
UserData& UserData::getInstance()
{
    inGameCurrency = 500;
    _instanceCount++;
    if (_instance == nullptr)
    {
        _instance = new UserData;
    }
    return *_instance;
}
void UserData::releaseInstance()
{
    _instanceCount--;
    if (_instanceCount == 0 && _instance != nullptr)
    {
        delete _instance;
        _instance = nullptr;
    }
    return;
}

UserData::UserData()
{
    Init();
}
UserData::~UserData() {}

void UserData::Init()
{
    inGameCurrency = 500;
}


UserData* UserData::_instance = nullptr;
int UserData::_instanceCount = 0;
int UserData::currency = 0;
int UserData::inGameCurrency = 50;
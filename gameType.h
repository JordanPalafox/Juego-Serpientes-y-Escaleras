#include <iostream>

using namespace std;

class GameType
{
public:
    virtual char getNextOption();
};

class ManualGame : public GameType
{
public:
    char getNextOption();
};

class AutomaticGame : public GameType
{
public:
    char getNextOption();
};

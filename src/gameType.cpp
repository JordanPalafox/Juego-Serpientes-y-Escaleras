#include "gameType.h"

char GameType::getNextOption()
{
    return ' ';
}

char ManualGame::getNextOption()
{
    char option;
    cin >> option;
    return option;
}

char AutomaticGame::getNextOption()
{
    return 'C';
}

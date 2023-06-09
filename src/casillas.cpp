#include <vector>
#include <cstdlib>
#include "casillas.h"

char CasillaNormal::getTipo() const
{
    return 'N';
}

int CasillaNormal::getPoints() const
{
    return points;
}

CasillaSerpiente::CasillaSerpiente(int penalty) : penalty(penalty)
{
}

char CasillaSerpiente::getTipo() const
{
    return 'S';
}

int CasillaSerpiente::getPoints() const
{
    return penalty;
}

CasillaEscalera::CasillaEscalera(int reward) : reward(reward)
{
}

char CasillaEscalera::getTipo() const
{
    return 'L';
}

int CasillaEscalera::getPoints() const
{
    return reward;
}

Board::Board(int total, int escaleras, int serpientes, int penalty, int reward)
{
    for (int i = 0; i < total; ++i)
    {
        casillas.push_back(new CasillaNormal());
    }

    for (int i = 0; i < serpientes; ++i)
    {
        int posicion = rand() % total;
        while (casillas[posicion]->getTipo() != 'N' || posicion < penalty)
        {
            posicion = rand() % total - 1;
        }
        casillas[posicion] = new CasillaSerpiente(penalty);
    }

    for (int i = 0; i < escaleras; ++i)
    {
        int posicion = rand() % total;
        while (casillas[posicion]->getTipo() != 'N' || posicion == 1)
        {
            posicion = rand() % total;
        }
        casillas[posicion] = new CasillaEscalera(reward);
    }
}

vector<Casilla *> Board::getCasillas() const
{
    return casillas;
}

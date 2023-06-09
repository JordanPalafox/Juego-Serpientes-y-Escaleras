#include "jugador.h"


Jugador::Jugador(int jugador, int posicion, int turno, int posicionFinal)
{
    this->jugador = jugador;
    this->posicion = posicion;
    this->turno = turno;
    this->posicionFinal = posicionFinal;
}

int Jugador::getJugador()
{
    return jugador;
}

int Jugador::getPosicion()
{
    return posicion;
}

int Jugador::getTurno()
{
    return turno;
}

int Jugador::getPosicionFinal()
{
    return posicionFinal;
}

void Jugador::setJugador(int jugador)
{
    this->jugador = jugador;
}

void Jugador::setPosicion(int posicion)
{
    this->posicion = posicion;
}

void Jugador::setTurno(int turno)
{
    this->turno = turno;
}

void Jugador::setPosicionFinal(int posicionFinal)
{
    this->posicionFinal = posicionFinal;
}

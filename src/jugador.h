class Jugador
{
    private:
        int jugador;
        int posicion;
        int turno;
        int posicionFinal;
    public:
        Jugador(int, int, int, int);
        int getJugador();
        int getPosicion();
        int getTurno();
        int getPosicionFinal();
        void setJugador(int);
        void setPosicion(int);
        void setTurno(int);
        void setPosicionFinal(int);
};

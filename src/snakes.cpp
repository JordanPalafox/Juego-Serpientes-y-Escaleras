#include <iostream>
#include <vector>
#include <ctime>
#include "dice.cpp"
#include "jugador.cpp"
#include "casillas.cpp"
#include "gameType.cpp"

using namespace std;

class MyGame
{
public:
    void start()
    {
        int total = 30;
        int escaleras = 3;
        int serpientes = 3;
        int penalty = 3;
        int reward = 5;
        int numeroJugadores = 2;
        cout << "Ingrese el numero de casillas: " << endl;
        cin >> total;
        cout << "Ingrese el numero de escaleras: " << endl;
        cin >> escaleras;
        cout << "Ingrese el numero de serpientes: " << endl;
        cin >> serpientes;
        cout << "Ingrese el numero de casillas de penalizacion: " << endl;
        cin >> penalty;
        cout << "Ingrese el numero de casillas de recompensa: " << endl;
        cin >> reward;
        cout << "Ingrese el numero de jugadores: " << endl;
        cin >> numeroJugadores;
        cout << "Select type of game: " << endl << "1. Manual" << endl << "2. Automatico" << endl;
        int type;
        cin >> type;
        srand(time(0));

        //Genero el tablero y lo guardo en un vector
        Board tablero(total, escaleras, serpientes, penalty, reward);
        vector<Casilla *> board = tablero.getCasillas();

        //Imprime el tablero generado
        cout << "Tablero generado: " << endl;
        for (int i = 0; i < board.size(); ++i)
        {
            cout << board[i]->getTipo() << " ";
        }

        // Genero los jugadores y los guardo en un vector
        vector<Jugador> jugadores;
        for (int i = 1; i <= numeroJugadores; ++i)
        {
            Jugador jugador(i, 1, i, 1);
            jugadores.push_back(jugador);
        }

        // Genero el dado
        Dice dado;

        // Inicio el juego
        GameType *gameType;
        bool gameOver = false;
        if (type == 1)
        {
            gameType = new ManualGame();
            cout << "Press C to continue next turn, or E to end the game" << endl;
        }
        else if (type == 2)
        {
            gameType = new AutomaticGame();
        } 
        for (int i = 1; i <= board.size(); ++i)
        {
            char option;
            option = gameType->getNextOption();
            if (option == 'C')
            {
                for (int j = 0; j < jugadores.size(); ++j)
                {
                    int turno = jugadores[j].getTurno();
                    int posicion = jugadores[j].getPosicion();
                    int jugador = jugadores[j].getJugador();
                    int posicionFinal = jugadores[j].getPosicionFinal();
                    char casilla;

                    if (turno == i)
                    {
                        int dadoValue = dado.roll();
                        int nuevaPosicion = posicion + dadoValue;
                        if (nuevaPosicion > board.size())
                        {
                            nuevaPosicion = board.size();
                            gameOver = true;
                        }
                        else
                        {
                            nuevaPosicion = nuevaPosicion;
                            casilla = 'N';
                        }
                        if (board[nuevaPosicion - 1]->getTipo() == 'L')
                        {
                            nuevaPosicion = nuevaPosicion + board[nuevaPosicion - 1]->getPoints();
                            casilla = 'L';
                        }
                        else if (board[nuevaPosicion - 1]->getTipo() == 'S')
                        {
                            nuevaPosicion = nuevaPosicion - board[nuevaPosicion - 1]->getPoints();
                            casilla = 'S';
                        }
                        else
                        {
                            nuevaPosicion = nuevaPosicion;
                            casilla = 'N';
                        }
                        if (nuevaPosicion == board.size())
                        {
                            nuevaPosicion = board.size();
                            gameOver = true;
                        }
                        else if (nuevaPosicion > board.size())
                        {
                            nuevaPosicion = board.size();
                            gameOver = true;
                        }
                        jugadores[j].setPosicion(nuevaPosicion);
                        jugadores[j].setTurno(turno + jugadores.size());
                        jugadores[j].setPosicionFinal(posicionFinal);
                        cout << i << " " << jugador << " " << posicion << " " << dadoValue << " " << casilla << " " << nuevaPosicion << endl;
                        if (gameOver == true)
                        {
                            cout << "--GAME OVER--" << endl;
                            cout << "Player " << jugador << " is the winner!!!" << endl;
                            break;
                        }
                    }
                }
            }
            else if (option == 'E')
            {
                cout << "Thanks for playing!!!" << endl;
                break;
            }
            else
            {
                cout << "Invalid option, please press C to continue next turn or E to end the game" << endl;
                i = i - 1;
            }
            if (gameOver == true)
            {
                break;
            }
        }
        if (gameOver == false)
        {
            cout << "--GAME OVER--" << endl;
            cout << "No one is the winner!!!" << endl;
        }
    }
};

int main()
{
    MyGame g;
    g.start();
    return 0;
}
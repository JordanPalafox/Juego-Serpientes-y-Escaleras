#include <vector>

using namespace std;

// Clase base abstracta para Casilla
class Casilla
{
public:
    virtual char getTipo() const = 0;
    virtual int getPoints() const = 0;
    virtual ~Casilla() {} // Añade un destructor virtual para la clase base
};

// Clase derivada para Casilla Normal
class CasillaNormal : public Casilla
{
private:
    int points;

public:
    char getTipo() const override;
    int getPoints() const override;
};

// Clase derivada para Casilla Serpiente
class CasillaSerpiente : public Casilla
{
private:
    int penalty;

public:
    CasillaSerpiente(int penalty);
    char getTipo() const override;
    int getPoints() const override;
};

// Clase derivada para Casilla Escalera
class CasillaEscalera : public Casilla
{
private:
    int reward;

public:
    CasillaEscalera(int reward);
    char getTipo() const override;
    int getPoints() const override;
};

// Clase Board
class Board
{
private:
    vector<Casilla *> casillas;

public:
    Board(int total, int escaleras, int serpientes, int penalty, int reward);
    vector<Casilla *> getCasillas() const;
};

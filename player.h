#ifndef PLAYER_H
#define PLAYER_H
#include "carta.h"
#include <QMap>

class Player
{    
public:
    QVector<Carta> CartasEnJuego;
    QVector<Carta> Carton;
    int puntaje;

    void eliminar_carta(int);
    bool verificarTresCartasIguales();
};

#endif // PLAYER_H

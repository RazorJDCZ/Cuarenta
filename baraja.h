#ifndef BARAJA_H
#define BARAJA_H
#include "carta.h"
#include <QVector>
#include <random>

class Baraja {

public:
    QVector<Carta*> baraja;
    Baraja();
    void agregarCarta(Carta*);
    void barajar();
    void eliminarCarta(Carta*);
    //void verificar_cartas();
};

#endif // BARAJA_H

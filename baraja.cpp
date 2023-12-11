#include "baraja.h"
#include <QDebug>

Baraja::Baraja()
{
}

void Baraja::agregarCarta(Carta *cartaAgregar)
{
    baraja.push_back(cartaAgregar);
}

void Baraja::barajar(){
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count(); //Genera una semilla aleatoria en base al tiempo desde 1970 hasta la actualidad
    shuffle(baraja.begin(), baraja.end(), std::default_random_engine(seed));
}

void Baraja::eliminarCarta(Carta * cartaEliminar)
{
    baraja.removeOne(cartaEliminar);
}

/*
void Baraja::verificar_cartas()
{
    for(int i = 0; i < baraja.size(); i++){
        qDebug()<<baraja[i]->imagen_carta;
    }
}*/

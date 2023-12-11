#include "game.h"
#include <QDebug>


void Game::crearMazo()
{
    QString palos[4] = {"c", "p", "t", "d"};
    for(int i = 0; i < 4; i++){
        for(int j = 1; j <= 10; j++){
            QString fileName = QString::number(j) + palos[i] + ".jpg";
            Carta *cartainsert = new Carta(j,fileName);
            baraja_juego.agregarCarta(cartainsert);
        }
    }
    baraja_juego.barajar();
}

QVector<Carta> Game::repartir()
{
    QVector <Carta> cartas_entregar;
    for(int i = 0;i < 5; i++){
        Carta* carta_a_pasar = baraja_juego.baraja.takeAt(0);
        cartas_entregar.append(*carta_a_pasar);
    }
    for(int i = 0;i < 5; i++){
        qDebug()<<cartas_entregar[i].valor;
    }
    return cartas_entregar;
}

void Game::repartir_jugadores()
{
    Jugador.CartasEnJuego = repartir();
    Oponente.CartasEnJuego = repartir();
}

void Game::agregar_carta_mesa(Carta* carta_tirada)
{
    cartas_en_mesa.push_back(carta_tirada);
}

void Game::eliminar_carta(Carta * cartaEliminar)
{
    cartas_en_mesa.removeOne(cartaEliminar);
}

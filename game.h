#ifndef GAME_H
#define GAME_H
#include "baraja.h"
#include "player.h"

class Game
{
public:
    Baraja baraja_juego;
    QVector<Carta*> cartas_en_mesa;
    Player Jugador;
    Player Oponente;

    void crearMazo();
    QVector <Carta> repartir();
    void repartir_jugadores();
    void agregar_carta_mesa(Carta *);
    void eliminar_carta(Carta *);


};

#endif // GAME_H

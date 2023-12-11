#include "player.h"


void Player::eliminar_carta(int pos)
{
    CartasEnJuego.remove(pos);
}

bool Player::verificarTresCartasIguales()
{
    QMap<int, int> contadorValores;
    for (const Carta &carta : CartasEnJuego) {
        contadorValores[carta.valor]++;
        if (contadorValores[carta.valor] == 3) {
            return true;
        }
    }
    return false;

}

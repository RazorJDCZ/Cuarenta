#include "carta.h"

Carta::Carta()
{
    valor = 0;
    imagen_carta = "none";
}

Carta::Carta(int valor, QString im)
{
    this->valor = valor;
    imagen_carta = im;
}

void Carta::setImagen(QString im)
{
    imagen_carta = im;
}

QString Carta::getImagen()
{
    return imagen_carta;
}

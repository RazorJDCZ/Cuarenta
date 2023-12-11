#ifndef CARTA_H
#define CARTA_H
#include <QObject>
#include <QDebug>

class Carta
{    
public:
    Carta();
    Carta(int, QString);
    void setImagen(QString);
    QString getImagen();

    int valor; //No se toman en cuenta los perros en las cartas unicamente y ademas los numeros 8,9,10 se respresentan como J,Q,K
    QString imagen_carta;

    friend QDebug operator<<(QDebug dbg, const Carta &c) {
        dbg  << "Valor: " << c.valor << ", Imagen: " << c.imagen_carta;
        return dbg;
    }
};

#endif // CARTA_H

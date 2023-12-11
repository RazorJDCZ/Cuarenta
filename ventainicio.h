#ifndef VENTAINICIO_H
#define VENTAINICIO_H

#include <QMainWindow>

namespace Ui {
class VentaInicio;
}

class VentaInicio : public QMainWindow
{
    Q_OBJECT

public:
    explicit VentaInicio(QWidget *parent = nullptr);
    ~VentaInicio();

public slots:
    void empezar_juego();

private:
    Ui::VentaInicio *ui;
};

#endif // VENTAINICIO_H

#include "ventainicio.h"
#include "ui_ventainicio.h"
#include "mainwindow.h"

VentaInicio::VentaInicio(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::VentaInicio)
{
    ui->setupUi(this);
    connect(ui->Start, &QPushButton::clicked, this, &VentaInicio::empezar_juego);
}



VentaInicio::~VentaInicio()
{
    delete ui;
}

void VentaInicio::empezar_juego()
{
    MainWindow *m = new MainWindow;
    this->close();
    m->show();

    m->iniciar_juego();
    m->verificarRonda();
    m->mostrarCartaInicio();

    /*if(m->comprobar_baraja() or m->contar_perros()){
        m->Partida.repartir_jugadores();
        m->verificarRonda();
        m->mostrarCartaInicio();
    }*/


}

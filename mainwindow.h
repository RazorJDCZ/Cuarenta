#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDialog>
#include <QMainWindow>
#include <QPushButton>
#include <QMessageBox>
#include "game.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void iniciar_juego();
    void mostrarCartaInicio();
    void mostrarCartaCentro();
    void verificarRonda();
    void tira_carta_oponente();
    void comprobar_cartas_centro(Carta*, Player&);
    bool comprobar_jugada();
    bool comprobar_baraja();
    bool contar_perros();
    void contar_carton();

    QMessageBox msgbox;
    Game Partida;
    QPushButton* cartas_Jugador[5];
    QPushButton* cartas_oponente[5];
    QPushButton* carta_presionada;
    QPushButton* cartas_Mesa[9];
    QSet<int> numerosGenerados;

   
public slots:
    void tirar_carta_jugador();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

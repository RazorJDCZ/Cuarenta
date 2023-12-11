#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <cstdlib>
#include <ctime>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    //Para que no se puedan clickear las cartas del oponente
    ui->CartaO1->setEnabled(false);
    ui->CartaO2->setEnabled(false);
    ui->CartaO3->setEnabled(false);
    ui->CartaO4->setEnabled(false);
    ui->CartaO5->setEnabled(false);

    //Para esconder temporalmente las cartas del centro y no dejar que se puedan pulsar
    ui->CartaCentro1->setEnabled(false);
    ui->CartaCentro1->hide();
    ui->CartaCentro2->setEnabled(false);
    ui->CartaCentro2->hide();
    ui->CartaCentro3->setEnabled(false);
    ui->CartaCentro3->hide();
    ui->CartaCentro4->setEnabled(false);
    ui->CartaCentro4->hide();
    ui->CartaCentro5->setEnabled(false);
    ui->CartaCentro5->hide();
    ui->CartaCentro6->setEnabled(false);
    ui->CartaCentro6->hide();
    ui->CartaCentro7->setEnabled(false);
    ui->CartaCentro7->hide();
    ui->CartaCentro8->setEnabled(false);
    ui->CartaCentro8->hide();
    ui->CartaCentro9->setEnabled(false);
    ui->CartaCentro9->hide();

    //Inicializar las cartas del jugador
    cartas_Jugador[0] = ui->CartaJ1;
    cartas_Jugador[1] = ui->CartaJ2;
    cartas_Jugador[2] = ui->CartaJ3;
    cartas_Jugador[3] = ui->CartaJ4;
    cartas_Jugador[4] = ui->CartaJ5;

    //Inicializar las cartas de la mesa
    cartas_Mesa[0] = ui->CartaCentro1;
    cartas_Mesa[1] = ui->CartaCentro2;
    cartas_Mesa[2] = ui->CartaCentro3;
    cartas_Mesa[3] = ui->CartaCentro4;
    cartas_Mesa[4] = ui->CartaCentro5;
    cartas_Mesa[5] = ui->CartaCentro6;
    cartas_Mesa[6] = ui->CartaCentro7;
    cartas_Mesa[7] = ui->CartaCentro8;
    cartas_Mesa[8] = ui->CartaCentro9;

    //Inicializar las cartas del jugador
    cartas_oponente[0] = ui->CartaO1;
    cartas_oponente[1] = ui->CartaO2;
    cartas_oponente[2] = ui->CartaO3;
    cartas_oponente[3] = ui->CartaO4;
    cartas_oponente[4] = ui->CartaO5;

    //Se inician los connect
    for (int i = 0; i < 5; ++i) {
        connect(cartas_Jugador[i], SIGNAL(clicked()), this, SLOT(tirar_carta_jugador()));
    }
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::iniciar_juego()
{
    Partida.Jugador.puntaje = 0;
    Partida.Oponente.puntaje = 0;
    Partida.crearMazo();
    Partida.repartir_jugadores();
    ui->PuntuacionJ->setNum(Partida.Jugador.puntaje);
    ui->PuntuacionO->setNum(Partida.Oponente.puntaje);
}

void MainWindow::mostrarCartaInicio()
{
    for (int i = 0; i < 5; ++i) {
        QString nombreCarta = QString("CartaJ%1").arg(i + 1);
        QString imgCarta = Partida.Jugador.CartasEnJuego[i].imagen_carta;
        cartas_Jugador[i]->setStyleSheet("#"+nombreCarta+"{ background-image: url(://" + imgCarta + ") }");
    }
}

void MainWindow::mostrarCartaCentro()
{
    {
        for (int i = 0; i <  Partida.cartas_en_mesa.size(); i++) {
            QString nombreCarta = QString("CartaCentro%1").arg(i + 1);
            QString imgCarta = Partida.cartas_en_mesa[i]->imagen_carta;
            qDebug()<<nombreCarta<<" "<<imgCarta;
            cartas_Mesa[i]->show();
            cartas_Mesa[i]->setStyleSheet("#"+nombreCarta+"{ background-image: url(://" + imgCarta + ") }");
        }
    }
}

void MainWindow::verificarRonda()
{
    if(Partida.Jugador.verificarTresCartasIguales() or Partida.Oponente.verificarTresCartasIguales()){
        msgbox.setWindowTitle("RONDA");
        msgbox.setIcon(QMessageBox::Warning);
        msgbox.setText("DOS POR GUAPO");
        msgbox.exec();
    }
}

void MainWindow::tira_carta_oponente()
{
    srand((unsigned)int(time(NULL)));
    int numalea;
    do {
        numalea = rand() % 5 + 0;
    } while (numerosGenerados.contains(numalea));

    numerosGenerados.insert(numalea);

    cartas_oponente[numalea]->hide();
    Carta *cartaJugada2 = new Carta();
    cartaJugada2 = &Partida.Oponente.CartasEnJuego[numalea];
    //qDebug() << "En oponente: " << cartaJugada2->valor;
    Partida.agregar_carta_mesa(cartaJugada2);
    mostrarCartaCentro();
    comprobar_cartas_centro(cartaJugada2, Partida.Oponente);
}

void MainWindow::comprobar_cartas_centro(Carta* cj, Player &quien)
{

    if (!Partida.cartas_en_mesa.isEmpty() and !(Partida.cartas_en_mesa.size() == 1)){
        //qDebug()<<"El vector tiene: "<<Partida.cartas_en_mesa.size();
        //for (int i = 0; i < Partida.cartas_en_mesa.size(); ++i) {
            //qDebug()<<"Carta: "<< *Partida.cartas_en_mesa[i];
        //}

        int pos = Partida.cartas_en_mesa.size() - 2;
        Carta* ultimoElemento = Partida.cartas_en_mesa[pos];
        //qDebug()<<"Ultima carta"<<ultimoElemento->valor;
        //qDebug()<<"Carta pasada"<<cj->valor;

        if (ultimoElemento->valor == cj->valor) {
            //qDebug()<<"Entro al primer if";
            quien.puntaje += 2;
            quien.Carton.push_back(*ultimoElemento);
            quien.Carton.push_back(*cj);
            cartas_Mesa[pos]->hide();
            cartas_Mesa[pos + 1]->hide();
            Partida.cartas_en_mesa.removeOne(ultimoElemento);
            Partida.cartas_en_mesa.removeOne(cj);

            msgbox.setWindowTitle("CAIDA");
            msgbox.setIcon(QMessageBox::Warning);
            msgbox.setText("DOS POR SHUNSHO");
            msgbox.exec();

        }
        else if(std::find_if(
                       Partida.cartas_en_mesa.begin(),
                       std::prev(Partida.cartas_en_mesa.end()), // Utiliza std::prev para apuntar al penúltimo elemento
                       [cj](const Carta* carta) { return carta->valor == cj->valor; }
                       ) != std::prev(Partida.cartas_en_mesa.end())) {
            //qDebug()<<"Entro al tercer if";
            for (int i = 0; i < Partida.cartas_en_mesa.size(); ++i) {
                if(cj->valor == Partida.cartas_en_mesa[i]->valor){
                    quien.Carton.push_back(*Partida.cartas_en_mesa[i]);
                    quien.Carton.push_back(*cj);
                    cartas_Mesa[i]->hide();
                    cartas_Mesa[Partida.cartas_en_mesa.size() - 1]->hide();
                    Partida.cartas_en_mesa.removeOne(Partida.cartas_en_mesa[i]);
                    Partida.cartas_en_mesa.removeOne(cj);
                    //qDebug()<<"Valor de i en el segundo if"<<i;
                }
            }
        }
        else{
               // qDebug()<<"Entro al segundo if";
                int pos1,pos2;
                bool se_puede_sumar = false;
                for(int i = 0; i < Partida.cartas_en_mesa.size(); i++){
                    for(int j = i+1; j < Partida.cartas_en_mesa.size(); j++){
                        if(Partida.cartas_en_mesa[i]->valor + Partida.cartas_en_mesa[j]->valor == cj->valor and Partida.cartas_en_mesa[i]->valor + Partida.cartas_en_mesa[j]->valor < 8){
                            pos1 = i;
                            pos2 = j;
                            //qDebug()<<"Valor i: "<<i<<"Valor j:"<<j<<"Valor pos1: "<<pos1<<"Valor pos2: "<<pos2;
                            se_puede_sumar = true;
                        }
                    }
                }
                if(se_puede_sumar){
                    quien.Carton.push_back(*Partida.cartas_en_mesa[pos1]);
                    quien.Carton.push_back(*Partida.cartas_en_mesa[pos2]);
                    quien.Carton.push_back(*cj);
                    cartas_Mesa[pos1]->hide();
                    cartas_Mesa[pos2]->hide();
                    cartas_Mesa[Partida.cartas_en_mesa.size() - 1]->hide();
                    Partida.cartas_en_mesa.removeOne(Partida.cartas_en_mesa[pos1]);
                    Partida.cartas_en_mesa.removeOne(Partida.cartas_en_mesa[pos2]);
                    Partida.cartas_en_mesa.removeOne(cj);
                }
                //for (int i = 0; i < quien.Carton.size(); ++i) {
                    //qDebug()<<"Carton"<<quien.Carton[i].valor;
                //}
            }
        }
    qDebug()<<"No entro al volver a repartir";
    if(comprobar_jugada()){
        qDebug()<<"Entro al volver a repartir";
        Partida.Jugador.CartasEnJuego.clear();
        Partida.Oponente.CartasEnJuego.clear();
        Partida.repartir_jugadores();
        for(int i = 0; i < 5; i++){
            cartas_Jugador[i]->show();
            cartas_oponente[i]->show();
        }
        for (int i = 0; i < 5; ++i) {
            qDebug()<<"Carta: "<< Partida.Jugador.CartasEnJuego[i];
            qDebug()<<"Carta: "<< Partida.Oponente.CartasEnJuego[i];
            }
        mostrarCartaInicio();
    }
}

bool MainWindow::comprobar_jugada()
{
    if(ui->CartaO1->isVisible() or ui->CartaO2->isVisible() or ui->CartaO3->isVisible() or ui->CartaO4->isVisible() or ui->CartaO5->isVisible()){
        return false;
    }else
        return true;
}

bool MainWindow::comprobar_baraja()
{
    if(Partida.baraja_juego.baraja.isEmpty()){
        return true;
    }else
        return false;
}

bool MainWindow::contar_perros()
{
    if(Partida.Jugador.puntaje == 40 or Partida.Oponente.puntaje == 40)
        return false;
    else
        return true;
}

void MainWindow::contar_carton()
{
    if(Partida.Jugador.Carton.size() > 19){
        switch (Partida.Jugador.Carton.size()) {
        case 20:
            Partida.Jugador.puntaje += 6;
            ui->PuntuacionJ->setNum(Partida.Jugador.puntaje);
            break;
        case 21:
        case 22:
            Partida.Jugador.puntaje += 8;
            ui->PuntuacionJ->setNum(Partida.Jugador.puntaje);
            break;
        case 23:
        case 24:
            Partida.Jugador.puntaje += 10;
            ui->PuntuacionJ->setNum(Partida.Jugador.puntaje);
            break;
        case 25:
        case 26:
            Partida.Jugador.puntaje += 12;
            ui->PuntuacionJ->setNum(Partida.Jugador.puntaje);
            break;
        case 27:
        case 28:
            Partida.Jugador.puntaje += 14;
            ui->PuntuacionJ->setNum(Partida.Jugador.puntaje);
            break;
        }
    }else if(Partida.Oponente.Carton.size() > 19){
        switch (Partida.Oponente.Carton.size()) {
        case 20:
            Partida.Oponente.puntaje += 6;
            ui->PuntuacionJ->setNum(Partida.Oponente.puntaje);
            break;
        case 21:
        case 22:
            Partida.Oponente.puntaje += 8;
            ui->PuntuacionJ->setNum(Partida.Oponente.puntaje);
            break;
        case 23:
        case 24:
            Partida.Oponente.puntaje += 10;
            ui->PuntuacionJ->setNum(Partida.Oponente.puntaje);
            break;
        case 25:
        case 26:
            Partida.Oponente.puntaje += 12;
            ui->PuntuacionJ->setNum(Partida.Oponente.puntaje);
            break;
        case 27:
        case 28:
            Partida.Oponente.puntaje += 14;
            ui->PuntuacionJ->setNum(Partida.Oponente.puntaje);
            break;
        }
    }
}

void MainWindow::tirar_carta_jugador()
{
    int posicion = -1;
    carta_presionada = qobject_cast<QPushButton*>(sender());

    for (int i = 0; i < 5; i++) {
        if (cartas_Jugador[i] == carta_presionada) {
            posicion = i;
            qDebug()<<posicion;
            break;
        }
    }
    cartas_Jugador[posicion]->hide();
    Carta *cartaJugada = new Carta();
    cartaJugada = &Partida.Jugador.CartasEnJuego[posicion];
    qDebug()<<"En Jugador: "<<cartaJugada->valor;
    Partida.agregar_carta_mesa(cartaJugada);
    comprobar_cartas_centro(cartaJugada, Partida.Jugador);
    mostrarCartaCentro();
    tira_carta_oponente();
    ui->PuntuacionJ->setNum(Partida.Jugador.puntaje);
    ui->PuntuacionO->setNum(Partida.Oponente.puntaje);
}

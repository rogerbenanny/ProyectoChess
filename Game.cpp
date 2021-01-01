#include "Game.h"
#include <QPixmap>
#include "Rey.h"
#include <QDebug>
#include <iostream>
#include "Boton.h"
#include <QMessageBox>
Game::Game(QWidget *parent ):QGraphicsView(parent)
{
    gameScene = new QGraphicsScene();
    gameScene->setSceneRect(0,0,1400,900);

    setFixedSize(1400,900);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setScene(gameScene);

    pieceToMove = nullptr;
    check = new QGraphicsTextItem();
    check->setPos(40,400);
    check->setZValue(4);
    check->setDefaultTextColor(Qt::red);
    check->setVisible(false);
    setTurn("WHITE");



    cronometroblancas = new QGraphicsTextItem();
    cronometroblancas->setPos(5,300);
    cronometroblancas->setFont(QFont("",14));

    cronometroblancas->setDefaultTextColor(Qt::black);
    cronometronegras = new QGraphicsTextItem();
    cronometronegras->setPos(1134,300);
    cronometronegras->setFont(QFont("",14));

    cronometronegras->setDefaultTextColor(Qt::black);

    logblancas = new QGraphicsTextItem();
    logblancas->setPos(5,600);
    logblancas->setFont(QFont("",14));

    logblancas->setDefaultTextColor(Qt::black);


    lognegras = new QGraphicsTextItem();
    lognegras->setPos(1140,600);
    lognegras->setFont(QFont("",14));

    lognegras->setDefaultTextColor(Qt::black);
}
void Game::cronometro(){

    if(getTurn()=="WHITE"){
    cronometroblancas->setPlainText("Cronometro Blancas:\n"+QString::fromStdString(cron->imprimir()));
    cron->restar();
    }else{
        cronometronegras->setPlainText("Cronometro Negras:\n"+QString::fromStdString(cron2->imprimir()));
        cron2->restar();
    }
}
void Game::drawTablero()
{
    chess = new Tablero();
    drawDeadHolder(0,0,Qt::white);
    drawDeadHolder(1100,0,Qt::white);
    DibujarRectangulos(271,25,Qt::white);
    DibujarRectangulos(1100,25,Qt::white);
     chess->DibujarCasillas(300,25);

}

void Game::DibujarLetrasYNumeros()
{

    QString f[8] = {"A","B","C","D","E","F","G","H"};
    QString g[8] = {"8","7","6","5","4","3","2","1"};
    for(int i=0; i<8; ++i){

           QGraphicsTextItem *text = new QGraphicsTextItem();
           text->setDefaultTextColor(Qt::black);
           text->setFont(QFont("",18));
           text->setPlainText(g[i]);
           text->setPos(275,60+i*100);
           AgregarItem(text);

    }
    for(int i=0; i<8; ++i){

           QGraphicsTextItem *text = new QGraphicsTextItem();
           text->setDefaultTextColor(Qt::black);
           text->setFont(QFont("",18));
           text->setPlainText(g[i]);
           text->setPos(1105,60+i*100);
           AgregarItem(text);

    }
    for(int i=0; i<8; ++i){

           QGraphicsTextItem *text = new QGraphicsTextItem();
           text->setDefaultTextColor(Qt::black);
           text->setFont(QFont("",18));
           text->setPlainText(f[i]);
           text->setPos(335+i*100,-5);
           AgregarItem(text);

    }
    for(int i=0; i<8; ++i){

           QGraphicsTextItem *text = new QGraphicsTextItem();
           text->setDefaultTextColor(Qt::black);
           text->setFont(QFont("",18));
           text->setPlainText(f[i]);
           text->setPos(335+i*100,820);
           AgregarItem(text);

    }

}

void Game::displayDeadWhite()
{
    int SHIFT = 50;
    int j = 0;
    int k = 0;
    for(size_t i = 0,n = static_cast<size_t>(whiteDead.size()); i<n; i++) {
            if(j == 4){
                k++;
                j = 0;
            }
            whiteDead[static_cast<int>(i)]->setPos(40+SHIFT*j++,100+SHIFT*2*k);
    }
}

void Game::displayDeadBlack()
{
    int SHIFT = 50;
    int j = 0;
    int k = 0;
    for(size_t i = 0,n = static_cast<size_t>(blackDead.size()); i<n; i++) {
        if(j == 4){
            k++;
            j = 0;
        }
        blackDead[static_cast<int>(i)]->setPos(1140+SHIFT*j++,100+SHIFT*2*k);
    }
}

void Game::placeInDeadPlace(Pieza *piece)
{
    if(piece->getSide() == "WHITE") {
        whiteDead.append(piece);
        Rey *g = dynamic_cast <Rey *>(piece);
        if(g){

            check->setPlainText("Ganan Negras");
            gameOver();
        }
        displayDeadWhite();
    }
    else{
        blackDead.append(piece);
        Rey *g = dynamic_cast <Rey *>(piece);
        if(g){

            check->setPlainText("Ganan Blancas");
            gameOver();
        }
        displayDeadBlack();
    }
    alivePiece.removeAll(piece);
}

void Game::AgregarItem(QGraphicsItem *item)
{
    gameScene->addItem(item);
}
QString Game::getTurn()
{
    return turn;
}

void Game::setTurn(QString value)
{
    turn = value;
}

void Game::start()
{
    logblancas->setPlainText(logb);
    lognegras->setPlainText(logn);

    AgregarItem(logblancas);
    AgregarItem(lognegras);

    for(size_t i =0, n = static_cast<size_t>(listG.size()); i < n; i++)
        removeFromScene(listG[static_cast<int>(i)]);

    QGraphicsTextItem* whitePiece = new QGraphicsTextItem();
    whitePiece->setPos(70,10);
    whitePiece->setZValue(1);
    whitePiece->setDefaultTextColor(Qt::black);
    whitePiece->setFont(QFont("",14));
    whitePiece->setPlainText("PIEZAS BLANCAS");
    AgregarItem(whitePiece);
    QGraphicsTextItem *blackPiece = new QGraphicsTextItem();

    blackPiece->setPos(1170,10);
    blackPiece->setZValue(1);
    blackPiece->setDefaultTextColor(Qt::black);
    blackPiece->setFont(QFont("",14));
    blackPiece->setPlainText("PIEZAS NEGRAS");
    AgregarItem(blackPiece);
    AgregarItem(check);
    chess->addPieza();
}



void Game::drawDeadHolder(int x, int y,QColor color)
{
    deadHolder = new QGraphicsRectItem(x,y,300,900);

    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(color);
    deadHolder->setBrush(brush);
    AgregarItem(deadHolder);
}

void Game::DibujarRectangulos(int x, int y, QColor color)
{
    deadHolder = new QGraphicsRectItem(x,y,29,900);

    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(color);
    deadHolder->setBrush(brush);
    AgregarItem(deadHolder);
}
void Game::displayMainMenu()
{

    QGraphicsTextItem *titleText = new QGraphicsTextItem("Ajedrez - TO");
    QFont titleFont("roboto" , 50);
    titleText->setFont( titleFont);
    int xPos = static_cast<int>(width()/2 - titleText->boundingRect().width()/2);
    int yPos = 150;
    titleText->setPos(xPos,yPos);
    AgregarItem(titleText);
    listG.append(titleText);
   // create Boton;
    Boton * playBoton = new Boton("Jugar con Cronometro");
    int pxPos = static_cast<int>(width()/2 - playBoton->boundingRect().width()/2);
    int pyPos = 300;
    playBoton->setPos(pxPos,pyPos);
    connect(playBoton,SIGNAL(clicked()) , this , SLOT(comenzarcronometro()));
    AgregarItem(playBoton);
    listG.append(playBoton);

}




QString Game::conversor(QString r, int x, int y,int& c)
{
    QString f[8] = {"a","b","c","d","e","f","g","h"};
    QString g[8] = {"8","7","6","5","4","3","2","1"};

    if(c==5){
        c=0;
        return "\n"+r+f[x]+g[y];
    }

    return r+f[x]+g[y];
}

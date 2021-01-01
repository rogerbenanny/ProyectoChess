#ifndef GAME_H
#define GAME_H


#include <QGraphicsView>
#include <QGraphicsScene>
#include "Tablero.h"
#include "Pieza.h"
#include "Tiempo.h"
class Game:public QGraphicsView
{
    Q_OBJECT
public:
    Game(QWidget *parent = nullptr);
    void drawDeadHolder(int x, int y, QColor color);
    void DibujarRectangulos(int x, int y, QColor color);
    void drawTablero();
    void displayDeadWhite();
    void displayDeadBlack();
    Pieza *pieceToMove; 
    QString getTurn() ;
    void setTurn( QString value);
    void changeTurn();
    Casilla *collection[8][8];
    QList <Pieza *> alivePiece;
    void displayMainMenu();
    QString conversor(QString r,int x, int y, int& c);
    QString logb = "LOG BLANCAS\n";
    QString logn = "LOG NEGRAS\n";
    QGraphicsTextItem* logblancas;
    QGraphicsTextItem* lognegras;
    int contb=0;
    int contn=0;
    bool isDead=false;

public slots:
    void start();
private:
    QGraphicsScene *gameScene;
    QList <Pieza *> whiteDead;
    QList <Pieza *> blackDead;
    QGraphicsRectItem * deadHolder;
    QString turn;
    Tablero *chess;
    QList <QGraphicsItem *> listG;

};

#endif 

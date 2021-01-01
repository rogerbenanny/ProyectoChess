#ifndef PIEZA_H
#define PIEZA_H


#include <QGraphicsPixmapItem>
#include "Casilla.h"
#include <QGraphicsSceneMouseEvent>

class Casilla;
class Pieza:public QGraphicsPixmapItem
{
public:
    Pieza(QString team = "",QGraphicsItem *parent = nullptr);

    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void setCurrentBox(Casilla *box);
    Casilla *getCurrentBox() ;
    QString getSide() ;z
    void setSide( QString value);
    bool getIsPlaced() ;
    void setIsPlaced(bool value);
    QList <Casilla *> moveLocation();
    virtual void Movimientos() = 0;
    virtual void SetImagen() = 0;

    void decolor();
    bool firstMove;

    bool boxSetting(Casilla *box);
protected:
    Casilla *currentBox;
    QString side;
    bool isPlaced;

    QList <Casilla *> location;

};

#endif 

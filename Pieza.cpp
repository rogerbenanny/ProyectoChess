#include "Pieza.h"
#include "Game.h"
#include <QDebug>
#include "Rey.h"
#include "iostream"

extern Game *game;
Pieza::Pieza(QString team, QGraphicsItem *parent):QGraphicsPixmapItem(parent)
{
    side = team;
    isPlaced = true;
    firstMove = true;
}

void Pieza::mousePressEvent(QGraphicsSceneMouseEvent *event)
{

    //Deselecccionar
    if(this == game->pieceToMove){
        game->pieceToMove->getCurrentBox()->resetOriginalColor();
        game->pieceToMove->decolor();
        game->pieceToMove = NULL;
       return;
    }
    //si no ha sido consumido
    if((!getIsPlaced() )|| ( (game->getTurn() != this->getSide())&& (!game->pieceToMove)) )
        return;
    //seleccionar
    if(!game->pieceToMove){



        game->pieceToMove = this;
        game->pieceToMove->getCurrentBox()->setColor(Qt::red);
        game->pieceToMove->Movimientos();


    }
    //consumiendo la otra casilla
    else if(this->getSide() != game->pieceToMove->getSide()){
        this->getCurrentBox()->mousePressEvent(event);
    }


}

void Pieza::setCurrentBox(Casilla *box)
{

    currentBox = box;
}

Casilla *Pieza::getCurrentBox()
{
    return currentBox;
}

QString Pieza::getSide()
{
    return side;
}

void Pieza::setSide( QString value)
{
    side = value;
}

bool Pieza::getIsPlaced()
{
    return isPlaced;
}

void Pieza::setIsPlaced(bool value)
{
    isPlaced = value;

}
QList<Casilla *> Pieza::moveLocation()
{
    return location;
}
void Pieza::decolor()
{
    for(size_t i = 0, n = static_cast<size_t>(location.size()); i < n;i++) {
         location[static_cast<int>(i)]->resetOriginalColor();
    }
}

bool Pieza::boxSetting(Casilla *box)
{
    if(box->getHasPieza()) {

        Rey *q = dynamic_cast<Rey*>(location.last()->currentPiece);
        if(q){
            box->setColor(Qt::blue);
        }
        else
            box->setColor(Qt::red);
        return true;

    }
    else
        location.last()->setColor(Qt::darkRed);
    return false;
}

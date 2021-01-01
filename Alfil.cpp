#include "Alfil.h"
#include <QDebug>
#include "Game.h"
extern Game *game;

Alfil::Alfil(QString team,QGraphicsItem *parent):Pieza(team,parent)
{
    SetImagen();
}

void Alfil::SetImagen()
{
    if(side == "WHITE")
        setPixmap(QPixmap(":/ima/Imagenes/alfilblanco.png"));
    else
        setPixmap(QPixmap(":/ima/Imagenes/alfilnegro.png"));
}



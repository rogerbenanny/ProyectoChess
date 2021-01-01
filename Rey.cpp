#include "Rey.h"
#include "Game.h"
#include "Peon.h"
extern Game *game;
Rey::Rey(QString team,QGraphicsItem *parent):Pieza(team,parent)
{
    SetImagen();
}

void Rey::SetImagen()
{
    if(side == "WHITE")
        setPixmap(QPixmap(":/ima/Imagenes/reyblanco.png"));
    else
        setPixmap(QPixmap(":/ima/Imagenes/reynegro.png"));
}



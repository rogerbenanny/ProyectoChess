#include "Caballo.h"
#include "Game.h"
extern Game *game;

Caballo::Caballo(QString team,QGraphicsItem *parent):Pieza(team,parent)
{
    SetImagen();
}

void Caballo::SetImagen()
{
    if(side == "WHITE")
        setPixmap(QPixmap(":/ima/Imagenes/caballoblanco.png"));
    else
        setPixmap(QPixmap(":/ima/Imagenes/caballonegro.png"));
}






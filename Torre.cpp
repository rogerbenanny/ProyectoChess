#include "Torre.h"
#include "Game.h"
extern Game *game;
Torre::Torre(QString team,QGraphicsItem *parent):Pieza(team,parent)
{
    SetImagen();
}
void Torre::SetImagen()
{
    if(side == "WHITE")
        setPixmap(QPixmap(":/ima/Imagenes/torreblanco.png"));
    else
        setPixmap(QPixmap(":/ima/Imagenes/torrenegra.png"));
}




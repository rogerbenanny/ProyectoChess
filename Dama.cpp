#include "Dama.h"
#include "Game.h"
extern Game *game;
Dama::Dama(QString team,QGraphicsItem *parent):Pieza(team,parent)
{
    SetImagen();
}
void Dama::SetImagen()
{
    if(side == "WHITE")
        setPixmap(QPixmap(":/ima/Imagenes/damablanca.png"));
    else
        setPixmap(QPixmap(":/ima/Imagenes/damanegra.png"));
}


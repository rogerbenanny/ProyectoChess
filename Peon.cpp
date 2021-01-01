#include "Peon.h"
#include "Game.h"
#include <QDebug>
#include <typeinfo>
#include "Rey.h"
#include "Dama.h"
extern Game * game;
Peon::Peon(QString team,QGraphicsItem *parent):Pieza(team,parent)
{
    SetImagen();
    firstMove = true;
}

void Peon::SetImagen()
{
    if(side == "WHITE")
        setPixmap(QPixmap(":/ima/Imagenes/peonblanco.png"));
    else
        setPixmap(QPixmap(":/ima/Imagenes/peonnegro.png"));
}







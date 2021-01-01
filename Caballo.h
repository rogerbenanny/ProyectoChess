#ifndef CABALLO_H
#define CABALLO_H
#include "Pieza.h"
class Caballo:public Pieza
{
public:
    Caballo(QString team,QGraphicsItem *parent = nullptr);
    void SetImagen();
};

#endif 

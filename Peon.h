#ifndef PEON_H
#define PEON_H
#include "Pieza.h"
class Peon:public Pieza
{
public:
    Peon(QString team,QGraphicsItem *parent = nullptr);
    void SetImagen();
    void Movimientos();
};
#endif 

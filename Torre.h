#ifndef TORRE_H
#define TORRE_H
#include "Pieza.h"
class Torre:public Pieza
{
public:
    Torre(QString team, QGraphicsItem *parent = nullptr);
    void SetImagen();
    void Movimientos();
};
#endif 

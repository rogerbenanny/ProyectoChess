#ifndef ALFIL_H
#define ALFIL_H
#include "Pieza.h"

class Alfil:public Pieza
{
public:
    Alfil(QString team,QGraphicsItem *parent = nullptr);
    void SetImagen();

};

#endif 

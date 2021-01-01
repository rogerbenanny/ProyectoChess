#ifndef REY_H
#define REY_H
#include "Pieza.h"
class Rey:public Pieza
{
public:
    Rey(QString team,QGraphicsItem *parent = nullptr);
    void SetImagen();
};

#endif 

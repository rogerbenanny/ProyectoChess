#ifndef TABLERO_H
#define TABLERO_H
#include <QGraphicsRectItem>
#include "Pieza.h"
class Tablero
{
public:
    Tablero();
    void DibujarCasillas(int x, int y);
    void ArmarNegras();
    void ArmarBlancas();
    void addPieza();
    void reset();
private:
    QList <Pieza *> white;
    QList <Pieza *> black;
};
#endif 

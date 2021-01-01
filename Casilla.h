#ifndef CASILLA_H
#define CASILLA_H


#include <QGraphicsRectItem>
#include <QBrush>
#include "Pieza.h"
#include <QGraphicsSceneMouseEvent>

class Pieza;
class Casilla:public QGraphicsRectItem
{
public:

    //Constructor
    Casilla(QGraphicsItem *parent=nullptr);
    ~Casilla();


    //public member function
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void setColor(QColor color);

    void placePiece(Pieza *piece);


    void resetOriginalColor();
    void setOriginalColor(QColor value);

    bool getHasPieza();
    void setHasPieza(bool value,Pieza *piece = nullptr);

    void checkForCheck();

    QString getPiezaColor() ;
    void setPiezaColor(QString value);



    int rowLoc;
    int colLoc;

    Pieza * currentPiece;

private:

    QBrush brush;
    QColor originalColor;
    bool hasPieza;

    QString PiezaColor;


};

#endif 

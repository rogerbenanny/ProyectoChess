#include "Tablero.h"
#include "Casilla.h"
#include "Game.h"
#include "Dama.h"
#include "Torre.h"
#include "Peon.h"
#include "Rey.h"
#include "Caballo.h"
#include "Alfil.h"
extern Game *game;
Tablero::Tablero()
{
    ArmarBlancas();
    ArmarNegras();
}
void Tablero::DibujarCasillas(int x,int y)
{
    int SHIFT = 100;
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++)
        {
            Casilla *box = new Casilla();
            game->collection[i][j] = box;
            box->rowLoc = i;
            box->colLoc = j;
            box->setPos(x+SHIFT*j,y+SHIFT*i);
            if((i+j)%2==0)
                box->setOriginalColor("#ffe0b9");
            else
                box->setOriginalColor("#d77c47");
            game->AgregarItem(box);

        }
    }

}


void Tablero::addPieza() {
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++)
        {

            Casilla *box =game->collection[i][j];

            if(i < 2) {
                static int k;
                box->placePiece(black[k]);

                game->alivePiece.append(black[k]);
                game->AgregarItem(black[k++]);
            }

            if(i > 5) {
                static int h;
                box->placePiece(white[h]);
                game->alivePiece.append(white[h]);
                game->AgregarItem(white[h++]);
            }

        }
    }
}

void Tablero::ArmarNegras()
{
    Pieza *piece;
    for(int i = 0; i < 8; i++) {
        piece = new Peon("WHITE");
        white.append(piece);
    }
    piece = new Torre("WHITE");
    white.append(piece);
    piece = new Caballo("WHITE");
    white.append(piece);
    piece = new Alfil("WHITE");
    white.append(piece);
    piece = new Dama("WHITE");
    white.append(piece);
    piece = new Rey("WHITE");
    white.append(piece);
    piece = new Alfil("WHITE");
    white.append(piece);
    piece = new Caballo("WHITE");
    white.append(piece);
    piece = new Torre("WHITE");
    white.append(piece);

}

void Tablero::ArmarBlancas()
{
    Pieza *piece;
    piece = new Torre("BLACK");
    black.append(piece);
    piece = new Caballo("BLACK");
    black.append(piece);
    piece = new Alfil("BLACK");
    black.append(piece);
    piece = new Dama("BLACK");
    black.append(piece);
    piece = new Rey("BLACK");
    black.append(piece);
    piece = new Alfil("BLACK");
    black.append(piece);
    piece = new Caballo("BLACK");
    black.append(piece);
    piece = new Torre("BLACK");
    black.append(piece);
    for(int i = 0; i < 8; i++) {
        piece = new Peon("BLACK");
        black.append(piece);
    }
}


void Tablero::reset() {
    int k = 0; int h = 0;
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++)
        {

            Casilla *box =game->collection[i][j];
            box->setHasPieza(false);
            box->setPiezaColor("NONE");
            box->currentPiece = nullptr;
            if(i < 2) {

                box->placePiece(black[k]);
                black[k]->setIsPlaced(true);
                black[k]->firstMove = true;
                game->alivePiece.append(black[k++]);

            }
            if(i > 5) {

                box->placePiece(white[h]);
                white[h]->setIsPlaced(true);
                white[h]->firstMove = true;
                game->alivePiece.append(white[h++]);

            }

        }
    }
}

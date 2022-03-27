#ifndef PAWN_H
#define PAWN_H

#include <string>
#include "Piece.h"

class Pawn: public Piece{//inheritance
private:
    bool promotion_p = false;
public:
    Pawn();
    bool special_move();
    bool promotion( int x, int y, int x1, int y1, char c);
    bool is_promoted();
};

#endif 
#ifndef ROOK_H
#define ROOK_H

#include <string>
#include "Piece.h"

class Rook: public Piece{//inheritance
private:

public: 
    Rook();
    bool special_move();
    bool legal_moves(std::string board[][6], int x, int y, int x1, int y1, char c) override;
};

#endif 
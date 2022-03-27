#ifndef KNIGHT_H
#define KNIGHT_H

#include <string>
#include "Piece.h"

class Knight: public Piece{//inheritance
private:

public: 
    Knight();
    bool special_move();
    bool legal_moves(std::string board[][6], int x, int y, int x1, int y1, char c) override;
};

#endif 
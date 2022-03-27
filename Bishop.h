#ifndef BISHOP_H
#define BISHOP_H

#include <string>
#include "Piece.h"

class Bishop: public Piece{//inheritance
private: 

public:
    Bishop();
    bool special_move();
    bool legal_moves(std::string board[][6], int x, int y, int x1, int y1, char c) override;
};

#endif 
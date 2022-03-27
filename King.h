#ifndef KING_H
#define KING_H

#include <string>
#include "Piece.h"

class King: public Piece{//inheritance
private: 

public: 
    King();
    bool special_move();
    bool legal_moves(std::string board[][6], int x, int y, int x1, int y1, char c) override;
};

#endif 
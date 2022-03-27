#ifndef QUEEN_H
#define QUEEN_H

#include <string>
#include "Piece.h"

class Queen: public Piece{//inheritance
private:

public: 
    Queen();
    bool special_move();
    bool legal_moves(std::string board[][6], int x, int y, int x1, int y1, char c) override;
};

#endif 
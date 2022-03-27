#ifndef BOARD_H
#define BOARD_H

#include <string>
#include <iostream>
#include <array>
#include <vector>
#include <chrono>
#include <thread>
#include <ncurses/ncurses.h>
#include "Piece.h"
#include "Player.h"
#include "King.h"
#include "Queen.h"
#include "Rook.h"
#include "Bishop.h"
#include "Pawn.h"
#include "Knight.h"

using namespace std::this_thread;     // sleep_for, sleep_until
using namespace std::chrono_literals; // ns, us, ms, s, h, etc.

class Board{
private: 
    std::string board[6][6];
    Piece pboard[6][6];
    int x, y, x_new, y_new;
    const char* arr[13] = {"wK", "wQ", "wB", "wN", "wR", "wP", "bK", "bQ", "bB", "bN", "bR", "bP", "\0"};
    King k1, k2;
    Queen q1, q2;
    Rook r1, r2;
    Bishop b1, b2;
    Knight n1, n2;
    Pawn p1, p2;

public: 
    void show_board();
    void show_board_old();
    void search_board(const char* d);
    void show_board_init();
    void instantiate(Player& player1, Player& player2);
    bool move_piece(int ind1, int ind2, char color);
    bool update_board(Piece& curr, int x1, int y1, char c);
    void update_player(int time_s, Player& player);
    void generate_board();
    void pawn_promotion(char c);
    void white_square(const char* d);
    void black_square(const char* d);
    ~Board();
};

#endif 
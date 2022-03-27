#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>
#include <thread>
#include "Piece.h"


using namespace std;
using namespace std::this_thread;     // sleep_for, sleep_until
using namespace std::chrono_literals; // ns, us, ms, s, h, etc.
using std::chrono::system_clock; //to get the time at the current state

const std::string name_txt = "Player_statistics_";

class Player{
private: 
    int time = 0;
    string name;
    int move_i = 0;
    static int pieces_added;//pieces attributes added
    int num_pieces = 6;//number of pieces player has
    int player_num;
    static int move_num;
    Piece piece[6];

public:
    int get_move();
    void move();
    void player_stats(int time_s, Piece& piece_w);
    void check_piece_stats(Piece& piece_w);
    void operator+= (Piece& _piece);//operator override
    static void increase_total_moves_count();
    static int get_total_moves();
    static void increase_pieces_added();
    void decrease_num_pieces();
    int get_num_pieces();
    Piece player_piece_array(int i);
    void set_player_number(int _num);
    friend std::istream& operator>>(std::istream& c, Player& _player);//friend function and operator override
    friend std::ostream& operator<<(std::ostream& c, const Player& _player);//friend functon and operator override
};

#endif 
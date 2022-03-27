#ifndef PIECE_H
#define PIECE_H

#include <string>
#include <iostream>
#include <cmath>

class Piece{
private: 
    std::string name;
    char short_name;
    int move_num;
    bool dest = false;
protected: 
    bool special = false;
    int attack;
    int health;
    int mana;
    
public:
    Piece();
    void set_name(std::string _name);
    std::string get_name();
    char get_short_name();
    void set_short_name(char _name);
    int get_attack();
    void manage_attack(int _attack); 
    virtual bool special_move();
    bool special_move_activated();
    int get_health();
    void manage_health(int _health);
    void set_health(int _health);
    int get_mana();
    void manage_mana(int _mana);
    void move_num_increase();
    int get_move_num();
    virtual bool legal_moves(std::string board[][6], int x, int y, int x1, int y1, char c);//need to update
    void operator=(char _assign);
    bool operator==(char c);
    bool operator==(Piece& c);
    void set_destroyed(bool a);
    bool get_destroyed();
    friend std::ostream& operator<<(std::ostream& c, const Piece& _piece);
};

#endif 
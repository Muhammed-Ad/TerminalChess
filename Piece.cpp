
#include "Piece.h"
Piece::Piece(){
    name = "";
    short_name = '\0';
    move_num = 0;
    attack = 0;
    health = 0;
    mana = 0;
}

void Piece::set_name(std::string _name){
    name = _name;
}
std::string Piece::get_name(){ return name; }
char Piece::get_short_name(){
    return short_name;
}
void Piece::set_short_name(char _name){
    short_name = _name;
}
int Piece::get_attack() { return attack; }
void Piece::manage_attack(int _attack){//add or remove mana
    if (_attack < 0){
        if (attack + _attack >= 0)
            attack += _attack;
        else{
            std::cout << "cannot have attack less than zero";
            return;
        }
    }    
    else {
        attack += _attack;    
    }
} 
bool Piece::special_move(){
    attack *= 2;
    special = true;
    return true;
}
bool Piece::special_move_activated(){
    return special;
}
int Piece::get_health() { return health;}
void Piece::manage_health(int _health){//add or remove health points
        health += _health;   
}
void Piece::set_health(int _health){
    health = _health;
}
int Piece::get_mana() { return mana; }
void Piece::manage_mana(int _mana){//add or remove mana
    if (_mana < 0){
        if (mana + _mana >= 0)
            mana += _mana;
        else{
            std::cout << "cannot have mana less than zero";
            return;
        }
    }    
    else {
        mana += _mana;    
    }
}
bool Piece::legal_moves(std::string board[][6], int x, int y, int x1, int y1, char c){
    if((c == 'w') && (x1 == x + 1) && (y1 == y))//regular pawn move
        return true;
    else if((c == 'b') && (x1 == x - 1) && (y1 == y))
        return true;

    if((c == 'w') && (x1 == x + 2) && (y1 == y) && (move_num == 0))//move two spaces on first move
        return true;
    else if((c == 'b') && (x1 == x - 2) && (y1 == y) && (move_num == 0))
        return true;
    
    if( (c == 'w') && (x1 == x + 1) && (y1 == y + 1) && !(board[x+1][y+1] == "\0") )  {//move diagonal +x and +y when there's a piece to attack, white pawn
        return true;
    }
    else if((c == 'w') && (x1 == x + 1) && (y1 == y - 1) && !(board[x+1][y-1] == "\0")){//move diagonal +x and -y when there's a piece to attack, white pawn
        return true;
    }
    else if((c == 'b') && (x1 == x - 1) && (y1 == y - 1) && !(board[x-1][y-1] == "\0")){//move diagonal -x and -y when there's a piece to attack, black pawn
        return true;
    }
    else if((c == 'b') && (x1 == x - 1) && (y1 == y + 1) && !(board[x-1][y+1] == "\0")){//move diagonal -x and +y when there's a piece to attack, black pawn
        return true;
    }
    return false;
}

void Piece::move_num_increase(){
    move_num++;
}
int Piece::get_move_num(){
    return move_num;
}
void Piece::operator=(char _assign){
    short_name = _assign;
}
bool Piece::operator==(char c){
    return (c == short_name);
}
bool Piece::operator==(Piece& c){
    return (c.get_name() == name);
}
void Piece::set_destroyed(bool a){
    if(a){
        mana = 0;
        attack = 0;
        health = 0;
    }
    dest = a;
}

bool Piece::get_destroyed(){
    return dest;
}

std::ostream& operator<<(std::ostream& c, const Piece& _piece){
    c << _piece.short_name;
    return c;
}
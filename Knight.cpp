#include "Knight.h"

Knight::Knight():Piece(){
    set_name("Knight");
    set_short_name('N');
    manage_attack(20);
    manage_mana(10);
    manage_health(215);
}
bool Knight::special_move(){
    attack *= 2;
    health += 50;
    std::cout << "the attack of your knight has been doubled and its gained back 50 health points" << std::endl;
    special = true;
    return true;
}


bool Knight::legal_moves(std::string board[][6], int x, int y, int x1, int y1, char c){
        if((x1 == x + 2) && (y1 == y + 1)){//move diagonal +2x and +1y
            return true;
        }
        else if((x1 == x + 2) && (y1 == y - 1)){//move diagonal +2x and -1y
            return true;
        }
        else if((x1 == x - 2) && (y1 == y - 1)){//move diagonal -2x and -1y
            return true;
        }
        else if((x1 == x - 2) && (y1 == y + 1)){//move diagonal -2x and +1y
            return true;
        }
        else if((x1 == x + 1) && (y1 == y + 2)){//move horizontal +1x +2y
            return true;
        }   
        else if((x1 == x - 1) && (y1 == y + 2)){//move horizontal -1x  +2y
            return true;
        }
        else if((x1 == x - 1) && (y1 == y - 2)){//move horizontal -1x -2y 
            return true;
        }
        else if((x1 == x + 1) && (y1 == y - 2)){//move horizontal +1x -2y 
            return true;
        }
    return false;
}
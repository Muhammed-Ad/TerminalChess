#include "King.h"

King::King():Piece(){
    set_name("King");
    set_short_name('K');
    manage_attack(20);
    manage_mana(10);
    manage_health(215);
}
bool King::special_move(){
    attack *= 3;
    std::cout << "the attack of your king has been tripled" << std::endl;
    special = true;
    return true;
}
bool King::legal_moves(std::string board[][6], int x, int y, int x1, int y1, char c){
        
        if((x1 == x + 1) && (y1 == y + 1)){//move diagonal +x and +y
            return true;
        }
        else if((x1 == x + 1) && (y1 == y - 1)){//move diagonal +x and -y
            return true;
        }
        else if((x1 == x - 1) && (y1 == y - 1)){//move diagonal -x and -y
            return true;
        }
        else if((x1 == x - 1) && (y1 == y + 1)){//move diagonal -x and +y
            return true;
        }
        else if((x1 == x + 1) && (y1 == y)){//move horizontal +x 
            return true;
        }   
        else if((x1 == x - 1) && (y1 == y)){//move horizontal -x
            return true;
        }
        else if((x1 == x) && (y1 == y + 1)){//move horizontal +y 
            return true;
        }
        else if((x1 == x) && (y1 == y - 1)){//move horizontal -y 
            return true;
        }
    return false;
}
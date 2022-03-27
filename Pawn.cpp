#include "Pawn.h"

Pawn::Pawn():Piece(){
    set_name("Pawn");
    set_short_name('P');
    manage_attack(20);
    manage_mana(10);
    manage_health(215);
}
bool Pawn::special_move(){
    health *= 3;
    attack *= 2;
    std::cout << "the health of your pawn has been tripled and attack doubled" << std::endl;
    special = true;
    return true;
}
bool Pawn::promotion( int x, int y, int x1, int y1, char c){
    for(int i = 0; i <= 5; i++){
        if(x == 4  && y == i && x1 == 5 && y1 == y - 1 && c == 'w'){//move diagonal -y
            promotion_p = true;
            return true;
        }
        else if(x == 4  && y == i && x1 == 5 && y1 == y + 1 && c == 'w'){//move diagonal +y
            promotion_p = true;
            return true;
        }
        else if(x == 4  && y == i && x1 == 5 && y1 == y && c == 'w'){//move vertical
            promotion_p = true;
            return true;
        }
        else if(x == 1 && y == i && x1 == 0 && y1 == y - 1 && c == 'b'){//same three types of movement, but for black
            promotion_p = true;
            return true;
        }
        else if(x == 1 && y == i && x1 == 0 && y1 == y + 1 && c == 'b'){
            promotion_p = true;
            return true;
        }
            
        else if(x == 1 && y == i && x1 == 0 && y1 == y && c == 'b'){
            promotion_p = true;
            return true;
        }
            
    }
    return false;
}
bool Pawn::is_promoted(){
    return promotion_p;
}

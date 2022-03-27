#include "Bishop.h"

Bishop::Bishop():Piece(){
    set_name("Bishop");
    set_short_name('B');
    manage_attack(20);
    manage_mana(10);
    manage_health(215);
}
bool Bishop::special_move(){
    attack *= 2;
    health *= 2;
    std::cout << "the attack and health of your bishop has been doubled" << std::endl;
    special = true ;
    return true;
}

bool Bishop::legal_moves(std::string board[][6], int x, int y, int x1, int y1, char c){
    for(int i = 1; i <= 5; i++){
        if((x1 == x + i) && (y1 == y + i)){//move diagonal +x and +y
            for(int j = 1; j < i; j++){//checking to see if there are any pieces along the path
                if(board[x+j][y+j] != "\0")
                    return false;
            }
            return true;
        }
        else if((x1 == x + i) && (y1 == y - i)){//move diagonal +x and -y
            for(int j = 1; j < i; j++){
                if(board[x+j][y-j] != "\0")
                    return false;
            }
            return true;
        }
        else if((x1 == x - i) && (y1 == y - i)){//move diagonal -x and -y
            for(int j = 1; j < i; j++){
                if(board[x-j][y-j] != "\0")
                    return false;
            }
            return true;
        }
        else if((x1 == x - i) && (y1 == y + i)){//move diagonal -x and +y
            for(int j = 1; j < i; j++){
                if(board[x-j][y+j] != "\0")
                    return false;
            }
            return true;
        }
    }
    return false;
}
#include "Queen.h"

Queen::Queen():Piece(){
    set_name("Queen");
    set_short_name('Q');
    manage_attack(20);
    manage_mana(10);
    manage_health(215);
}
bool Queen::special_move(){
    health *= 2;
    attack *= 2;
    std::cout << "the health and attack of your queen has been doubled"  << std::endl;
    special = true;
    return true;
}

bool Queen::legal_moves(std::string board[][6], int x, int y, int x1, int y1, char c){
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
        else if((x1 == x + i) && (y1 == y)){//move horizontal +x 
            for(int j = 1; j < i; j++){
                if(board[x+j][y] != "\0")
                    return false;
            }
            return true;
        }   
        else if((x1 == x - i) && (y1 == y)){//move horizontal -x 
            for(int j = 1; j < i; j++){
                if(board[x-j][y] != "\0")
                    return false;
            }
            return true;
        }
        else if((x1 == x) && (y1 == y + i)){//move horizontal +y 
            for(int j = 1; j < i; j++){
                if(board[x][y+j] != "\0")
                    return false;
            }
            return true;
        }
        else if((x1 == x) && (y1 == y - i)){//move horizontal -y 
            for(int j = 1; j < i; j++){
                if(board[x][y-j] != "\0")
                    return false;
            }
            return true;
        }
    }
    return false;
}
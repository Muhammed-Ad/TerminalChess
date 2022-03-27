#include "Player.h"


int Player::move_num = 0;
int Player::pieces_added = 0;

int Player::get_move(){
    return move_i;
}
void Player::increase_total_moves_count(){//use this
    move_num++;
}
int Player::get_total_moves(){
    return move_num;
}
void Player::move(){
    move_i++;
}
void Player::increase_pieces_added(){
    pieces_added++;
}
int Player::get_num_pieces(){
    return num_pieces;
}
void Player::decrease_num_pieces(){
    num_pieces -= 1;
}
void Player::player_stats(int time_s, Piece& piece_w){//polymorphism
    if(move_i == 1){
        std::ofstream file(name_txt + to_string(player_num) + ".txt", std::ios::trunc);//opens file to write to
        file.close();
    }
    std::ofstream file(name_txt + to_string(player_num) + ".txt", std::ios::app);//opens file to write to
    
    if (file){
        for(int i = 0; i < 6; i++){
            if(piece_w == piece[i]){
                file << piece_w.get_name() << ": " << std::endl
                << "Mana: " << piece_w.get_mana() << std::endl
                << "Attack: " << piece_w.get_attack() << std::endl
                << "Health: " << piece_w.get_health() << std::endl
                << "Destroyed: " << piece_w.get_destroyed() << std::endl;
                file  << "Time to make move: " << time_s << std::endl
                << "Move number: " << move_i << std::endl
                << "Total game moves (both players): " << move_num << std::endl;
                file.close();
                return;
            }
        }
    }
    file.close();
}
void Player::check_piece_stats(Piece& piece_w){
    for(int i = 0; i < 6; i++){
        if(piece_w == piece[i]){//checking if piece has reahc enough mana for special move
            if(( piece_w.get_destroyed() == true)){//checking if piece was destroyed and updating number of player pieces
                num_pieces--;
            }
            return;
        }
        
    }
}

Piece Player::player_piece_array(int i){
    return piece[i];
}
void Player::set_player_number(int _num){
    player_num = _num;
}
void Player::operator+= (Piece& _piece){
    piece[pieces_added] = _piece;
}
std::istream& operator>>(std::istream& c, Player& _player){
    c >> _player.name;
    return c;
}
std::ostream& operator<<(std::ostream& c, const Player& _player){
    c << _player.name;
    return c;
}
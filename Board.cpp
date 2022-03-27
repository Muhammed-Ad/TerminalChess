#include "Board.h"


void Board::update_player(int time_s, Player& player){//polymorphism
    player.move();//individual moves
    Player::increase_total_moves_count();//total moves
    player.player_stats(time_s, pboard[x_new][y_new]);
    player.check_piece_stats(pboard[x_new][y_new]);
    
}

void Board::generate_board(){
    for(int y = 0; y < 6; y++){
        board[0][y] = arr[y];
        board[5][5 - y] = arr[y + 6];
    }
    
    for(int x = 1; x < 5; x++){
        for(int y = 0; y < 6; y++){
            board[x][y] = arr[12];
        }
    }
}

void Board::show_board_old(){
    std::cout << "\n+-1-+-2-+-3-+-4-+-5-+-6-+";
    std::cout << "\n+---+---+---+---+---+---+\n";
    for(int x = 0; x < 6; x++){
        for(int y = 0; y < 6; y++){
            if(board[x][y] != "\0" && y == 5){
                std::cout << "| " << board[x][y] << "|";
                if(x == 0 && y == 5)
                    std::cout << " 1";
                else if(x == 1 && y == 5)
                    std::cout << " 2";
                else if(x == 2 && y == 5)
                    std::cout << " 3";
                else if(x == 3 && y == 5)
                    std::cout << " 4";
                else if(x == 4 && y == 5)
                    std::cout << " 5";
                else if(x == 5 && y == 5) 
                    std::cout << " 6";
            }    
            else if(board[x][y] != "\0")
                std::cout << "| " << board[x][y];
            else if(board[x][y] == "\0" && y == 5){
                std::cout << "| " << board[x][y] << "  |";
                if(x == 0 && y == 5)
                    std::cout << " 1";
                else if(x == 1 && y == 5)
                    std::cout << " 2";
                else if(x == 2 && y == 5)
                    std::cout << " 3";
                else if(x == 3 && y == 5)
                    std::cout << " 4";
                else if(x == 4 && y == 5)
                    std::cout << " 5";
                else if(x == 5 && y == 5) 
                    std::cout << " 6";
            }
            else
                std::cout << "| " << board[x][y] << "  ";
        }
        std::cout << "\n+---+---+---+---+---+---+\n";
    }
}

void Board::search_board(const char* d){
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 6; j++){
           if(board[i][j] == d){
               x = i;
               y = j;
               cout << "piece found";
               return;
           } 
        }
    }
    std::cout << "piece not found";
}

void Board::instantiate(Player& player1, Player& player2){//update
    player1 += k1;
    player2 += k2;
    pboard[0][0] = k1;
    pboard[5][5] = k2;
    Player::increase_pieces_added();

    player1 += q1;
    player2 += q2;
    pboard[0][1] = q1;
    pboard[5][4] = q2;
    Player::increase_pieces_added();
    
    player1 += b1;
    player2 += b2;
    pboard[0][2] = b1;
    pboard[5][3] = b2;
    Player::increase_pieces_added();

    player1 += n1;
    player2 += n2;
    pboard[0][3] = n1;
    pboard[5][2] = n2;
    Player::increase_pieces_added();

    player1 += r1;
    player2 += r2;
    pboard[0][4] = r1;
    pboard[5][1] = r2;
    Player::increase_pieces_added();

    player1 += p1;
    player2 += p2;
    pboard[0][5] = p1;
    pboard[5][0] = p2;
    Player::increase_pieces_added();
    
    for(int i = 1; i < 5; i++){
      for(int j = 0; j < 6; j++){
        pboard[i][j] = '\0';
      }
    }
}

void Board::pawn_promotion(char c){
    char promotion = '\0';
    if(p1.promotion(x, y, x_new, y_new, c)){//options for pawn promotion
        if(c == 'w'){
            p1.promotion(x, y, x_new, y_new, c);
        }
        else if (c == 'b'){
            p2.promotion(x, y, x_new, y_new, c);
        }
        
        std::cout << "What would you like to promote your pawn to?" << std::endl 
        << "\n(options: (k)ing, (q)ueen, (b)ishop, (r)ook, k(n)ight), or no (p)romotion): ";
        std::cin >> promotion;
        do{
            if(promotion == 'k'){
                King k11;
                pboard[x][y] = k11;
                std::cout << "Your pawn now has the properties of a " << pboard[x][y].get_name() << std::endl;
            }
            else if(promotion == 'q'){
                Queen q11;
                pboard[x][y] = q11;
                std::cout << "Your pawn now has the properties of a " << pboard[x][y].get_name() << std::endl;
            }
            else if(promotion == 'b'){
                Bishop b11;
                pboard[x][y] = b11;
                std::cout << "Your pawn now has the properties of a " << pboard[x][y].get_name() << std::endl;
            }
            else if(promotion == 'r'){
                Rook r11;
                pboard[x][y] = r11;
                std::cout << "Your pawn now has the properties of a " << pboard[x][y].get_name() << std::endl;
            }
            else if(promotion == 'n'){
                Knight n11;
                pboard[x][y] = n11;
                std::cout << "Your pawn now has the properties of a " << pboard[x][y].get_name() << std::endl;
            }
            else if(promotion == 'p'){
                pboard[x][y].set_health(200);
                std::cout << "Your pawn's health has been reset." << std::endl;
            }else{
                cout << "Your entry was not k, q, b, r, n, or p" << std::endl;
                cout << "Try again!" << std::endl;
            }
        }while(promotion != 'k' && promotion != 'q' && promotion != 'b' && promotion != 'r' && promotion != 'n' && promotion == 'p');    
    }
}

bool Board::move_piece(int ind1, int ind2, char color){
    bool is_valid = false;
    
    if ((pboard[x][y] == 'K') && (color == 'w')) {
        is_valid = update_board(k1, ind1, ind2, color);
    }
    else if ((pboard[x][y] == 'K') && (color == 'b')) {
        is_valid = update_board(k2, ind1, ind2, color);
    }
    else if (pboard[x][y] == 'Q' && (color == 'w')) {
        is_valid = update_board(q1, ind1, ind2, color);
    }
    else if ((pboard[x][y] == 'Q') && (color == 'b')) {
        is_valid = update_board(q2, ind1, ind2, color);
    }
    else if (pboard[x][y] == 'B' && (color == 'w')) {
        is_valid = update_board(b1, ind1, ind2, color);
    }
    else if ((pboard[x][y] == 'B') && (color == 'b')) {
        is_valid = update_board(b2, ind1, ind2, color);
    }
    else if (pboard[x][y] == 'R' && (color == 'w')) {
        is_valid = update_board(r1, ind1, ind2, color);
    }
    else if ((pboard[x][y] == 'R') && (color == 'b')) {
        is_valid = update_board(r2, ind1, ind2, color);
    }
    else if (pboard[x][y] == 'N' && (color == 'w')) {
        is_valid = update_board(n1, ind1, ind2, color);
    }
    else if ((pboard[x][y] == 'N') && (color == 'b')) {
        is_valid = update_board(n2, ind1, ind2, color);
    }
    else if (pboard[x][y] == 'P' && (color == 'w')) {
        is_valid = update_board(p1, ind1, ind2, color);
    }
    else if ((pboard[x][y] == 'P') && (color == 'b')) {
        is_valid = update_board(p2, ind1, ind2, color);
    }

    return is_valid;
}

bool Board::update_board(Piece& curr, int x1, int y1, char c){//polymorphism
    
    
    if(x1 > 5 || y1 > 5){
        std::cout << "That is not a legal move within the bounds of the board. Try again!" << std::endl;
        return false;
    }
    else if((x1 == x) && (y1 == y)){
        std::cout << "You cannot move to a spot you are already on. Try again!";
        return false;
    }
    bool is_legal;
    is_legal = curr.legal_moves(board, x, y, x1, y1, c);//polymorphism
    
    if(is_legal){
        std::cout << "\n\nThat was a legal move\n\n";
    }else{
        std::cout << "\n\nThat was NOT a legal move\n\n";
        return false;
    }
    
    x_new = x1;
    y_new = y1;

    if(pboard[x1][y1] == '\0'){ 
        if(board[x1][y1] == "\0"){//moving to empty spot
            if(pboard[x][y] == 'P'){//pawn promotion
                pawn_promotion(c); //check if pawn can be promoted
            }
            curr.move_num_increase();
            std::string temp1 = board[x1][y1];
            board[x1][y1] = board[x][y];
            board[x][y] = temp1;

            Piece temp2 = pboard[x1][y1];
            pboard[x1][y1] = pboard[x][y];
            pboard[x][y] = temp2;
        }
        show_board();//show black and white board
    }
    else if((pboard[x1][y1].get_health() <= pboard[x][y].get_attack())){//destroying a piece
        if(pboard[x1][y1].get_health() <= pboard[x][y].get_attack()){//piece is destroyed
            if(!(board[x1][y1][0] == board[x][y][0])){
                if(pboard[x][y] == 'P'){//pawn promotion
                    pawn_promotion(c); //check if pawn can be promoted
                }
                
                curr.move_num_increase();
                pboard[x1][y1].manage_health(curr.get_attack() * -1);
                pboard[x][y].manage_mana(25);
                if(pboard[x1][y1].get_health() <= 0){//check if piece destroyed
                    pboard[x1][y1].set_destroyed(true);
                    
                    std::cout << "Your " << pboard[x][y].get_name() << " has destroyed the opposing team's "
                    <<  pboard[x1][y1].get_name() << ". Mana is now " << pboard[x][y].get_mana() << std::endl
                    << "opposing team " << pboard[x1][y1].get_name() << "'s health is now " << pboard[x1][y1].get_health() << std::endl;

                    if(( pboard[x][y].get_mana() >= 100) && ( pboard[x][y].get_destroyed() == false) && !(curr.special_move_activated())){
                        std::cout << "Your " <<  pboard[x][y].get_name() << " has reached 100 mana." << std::endl
                        << "It's special move will now be activated." << std::endl;

                        curr.special_move(); pboard[x][y].manage_attack(curr.get_attack() - pboard[x][y].get_attack());
                    }

                    board[x1][y1] = board[x][y];
                    board[x][y] = "\0";

                    pboard[x1][y1] = pboard[x][y];
                    pboard[x][y] = '\0';
                }
            }else{
                std::cout << "You cannot attack your own pieces!" << std::endl;
                return false;
            }
        }
        show_board();//show black and white board
    }
    else if(!(pboard[x1][y1] == '\0')){//normal attack without destruction of piece
        if( (board[x1][y1] != "\0")){
            if(!(board[x1][y1][0] == board[x][y][0])){
                pboard[x][y].move_num_increase();
                pboard[x1][y1].manage_health(curr.get_attack() * -1);
                pboard[x][y].manage_mana(25);

                std::cout << "Your " << pboard[x][y].get_name() << " has attacked the opposing team's " << endl
                <<  pboard[x1][y1].get_name() << " with " << curr.get_attack() << " attack power."
                << " Mana is now " << pboard[x][y].get_mana() << std::endl << "opposing team " << pboard[x1][y1].get_name() 
                << "'s health is now " << pboard[x1][y1].get_health() << std::endl;

                if(( pboard[x][y].get_mana() >= 100) && ( pboard[x][y].get_destroyed() == false) && !(curr.special_move_activated())){
                    std::cout << "Your " <<  pboard[x][y].get_name() << " has reached 100 mana." << std::endl
                    << "Its special move will now be activated." << std::endl;

                    curr.special_move(); pboard[x][y].manage_attack(curr.get_attack() - pboard[x][y].get_attack());
                }
            } 
            else{
                std::cout << "You cannot attack your own pieces!" << std::endl;
                return false;
            }
        }
        show_board();//show black and white board
    }
    else{
        std::cout << "an error has occured in function update_board of class board.cpp";
        return false;
    }
    return true;
}


void Board::show_board(){
    initscr();//initiate ncurses
    noecho();
    cbreak();
    clear();
    addstr("   1      2      3      4      5      6   \n");
    refresh();
    const char* s = "  ";
    std::string ss = "\0";
    int l = 0;
    const char* dboard[6][3][2];
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 3; j++){
            for(int k = 0; k < 2; k++){
                dboard[i][j][k] = board[i][k+l].c_str();
            }
            l += 2;
        }
        l = 0;
    }
    
    start_color(); //starting color process in terminal

    for(int t = 0; t < 6; t++){//print out rows
        for(int q = 0; q < 3; q++){//n thickness of first row (1, 3, 5)
            for(int i = 0; i < 3; i++){//print even rows (start at 0)
                if(t%2 == 0){
                    
                    if(q == 1){
                        if(dboard[t][i][0][0] == *ss.c_str())
                            white_square(s);
                        else
                            white_square(dboard[t][i][0]);
                        if(dboard[t][i][1][0] == *ss.c_str())
                            black_square(s);
                        else
                            black_square(dboard[t][i][1]);
                    }else{
                        white_square(s);
                        black_square(s);
                    }
                }
                else if(t%2 == 1){//print odd rows (start at 0)
                    
                    if(q == 1){
                        if(dboard[t][i][0][0] == *ss.c_str())
                            black_square(s);
                        else
                            black_square(dboard[t][i][0]);
                        if(dboard[t][i][1][0] == *ss.c_str())
                            white_square(s);
                        else
                            white_square(dboard[t][i][1]);
                    }else{
                        black_square(s);
                        white_square(s);
                    }
                } 
            }
            if(q == 1){//print out numbers on side of board
                attroff(COLOR_PAIR(1));
                attroff(COLOR_PAIR(2));
                if(t == 0)    
                    addch('1');
                else if(t == 1)    
                    addch('2');
                else if(t == 2)
                    addch('3');
                else if(t == 3)
                    addch('4');
                else if(t == 4)
                    addch('5');
                else if(t == 5)
                    addch('6');
            }
            addch('\n');
        }
    }
    attroff(COLOR_PAIR(2)); 
    refresh();//refresh terminal windows to show board
    printw("\n\n\n     Press any key to make another move");
    int c = getch();//waits until user press a button to end window
}

Board::~Board(){
    endwin();
}


void Board::white_square(const char* d){
    init_pair(2, COLOR_BLACK, COLOR_WHITE);//characters are black, background is white
    attron(COLOR_PAIR(2));//use color pair 2 (white background, white square)
    addstr("   ");
    addstr(d);
    addstr("  ");
    
}

void Board::black_square(const char* d){
    init_pair(1, COLOR_WHITE, COLOR_BLACK);//characters are white, background is black
    attron(COLOR_PAIR(1));//use color pair 2 (black background, black square)
    addstr("   ");
    addstr(d);
    addstr("  ");
}

void Board::show_board_init(){
    
    initscr();//initiate ncurses
    noecho();
    cbreak();

    addstr("   1      2      3      4      5      6   \n");
    std::string s = "  ";

    start_color(); //starting color process in terminal

    for(int t = 0; t < 3; t++){//print n groups of first and second rows (1 and 2, 3 and 4, 5 and 6)
        for(int q = 0; q < 3; q++){//n thickness of first row (1, 3, 5)
            for(int i = 0; i < 3; i++){//print first row
                if(q == 1 && t == 0 && i == 0){
                    white_square("wK");
                    black_square("wQ");  
                }else if(q == 1 && t == 0 && i == 1){
                    white_square("wB");
                    black_square("wN");  
                }else if(q == 1 && t == 0 && i == 2){
                    white_square("wR");
                    black_square("wP");  
                }else{
                    white_square("  ");
                    black_square("  ");
                } 
            }
            if(q == 1){
                attroff(COLOR_PAIR(1));
                if(t == 0)    
                    addch('1');
                else if(t == 1)
                    addch('3');
                else if (t == 2)
                    addch('5');
            }
            addch('\n');
        }
            
        for(int q = 0; q < 3; q++){//n thickness of second row (2, 4, 6)
            for(int i = 0; i < 3; i++){//print second row
                if(q == 1 && t == 2 && i == 0){
                    black_square("bP");
                    white_square("bR");  
                }else if(q == 1 && t == 2 && i == 1){
                    black_square("bN");
                    white_square("bB");  
                }else if(q == 1 && t == 2 && i == 2){
                    black_square("bQ");
                    white_square("bK");  
                }else{
                    black_square("  ");
                    white_square("  ");
                }
            }
            if(q == 1){//adding the numbers on side
                attroff(COLOR_PAIR(1));
                if(t == 0)    
                    addch('2');
                else if(t == 1)
                    addch('4');
                else if (t == 2)
                    addch('6');     
            }
            addch('\n');
        }
    }  
    attroff(COLOR_PAIR(1));
    refresh();
    sleep_for(1s);
    printw("\n     The game will start momentarily\n");
    printw("\n     This will be your board \n");
    printw("\n     Player 1 will have white pieces (w)\n");
    printw("\n     Player 2 will have black pieces (b)\n");
    refresh();
    sleep_for(2s);
    printw("\n     loading...\n");
    refresh();
    sleep_for(3s);
    printw("\n     initializing...\n");
    refresh();
    sleep_for(4s);

    printw("\n     The game will start in 5...\n");
    refresh();
    sleep_for(1s);
    printw("\n     The game will start in 4...\n");
    refresh();
    sleep_for(1s);
    printw("\n     The game will start in 3...\n");
    refresh();
    sleep_for(1s);
    printw("\n     The game will start in 2...\n");
    refresh();
    sleep_for(1s);
    printw("\n     The game will start in 1...\n");
    refresh();
    sleep_for(1s);
    printw("\n\n\n     Press any key to make a move");
    refresh();//refresh terminal windows to show board
    int c = getch();
}


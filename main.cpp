/**
 *Author: Muhammed Ademola
 *
 * Description: This is a modified version of chess called ches war.
 * Please see the README file for more details
 */


#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <vector>
#include <stdlib.h>
#include <limits>
#include <ncurses/ncurses.h>
#include "Board.h"
#include "Piece.h"
#include "King.h"
#include "Queen.h"
#include "Rook.h"
#include "Bishop.h"
#include "Pawn.h"
#include "Knight.h"
#include "Player.h"


using namespace std;
using namespace std::this_thread;     // sleep_for, sleep_until
using namespace std::chrono_literals; // ns, us, ms, s, h, etc.
using std::chrono::system_clock; //to get the time at the current state


void welcome(){//welcome function
  cout << endl << "Welcome to the start of this Program!" << endl;
  cout << endl << "The name of the game is Chess War" << endl;
}
bool cin_good(){//functoin for error checking input
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  if (!cin.good()){
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << "Your input was not a number. Try again.\n\n";
      return false;
  }
  return true; 
}

int turns(const char* arr[], Player& player, int* p){//function for user input and displaying options
  cout << "Which piece do you want to move " << player << "? " << endl << endl;
  int choice = -1; 
  int board_num = 01; 
  bool correct = false;
  int n = *(p+2);
  do{//choose piece to move
    cout << endl << "You have a choice of \n1. " << arr[0 + n] << " (King)" 
    << "\n2. " << arr[1 + n] << " (Queen) " << "\n3. " << arr[2 + n] << " (Bishop) " 
    << "\n4. " << arr[3 + n] << " (Knight) " << "\n5. " << arr[4 + n] << " (Rook) " 
    << "\n6. " << arr[5 + n] << " (Pawn)" << endl; 
    
    cout << endl << "Enter in a number: ";
    cin.clear();
    cin >> choice;

    if(!cin_good())
      continue; 

    if(choice < 1 || choice > 6){
      cout << "Your choice must be a number between 1 and 6" << endl;
    }

  }while(choice < 1 || choice > 6);

  int arr_sub = choice + n - 1;
  cout << endl << "Where do you want to move " << arr[arr_sub] << "? " << endl;

  do{//choose where to move piece
    cout << "You have a choice of 11-16, 21-26, 31-36, 41-46, 51-56, 61-66. " << endl; 
    cout << "The first digit will move you down the board as the number goes up." << endl;
    cout << "The second digit will move you from left or right the board as the number goes up." << endl;
    
    cout << endl << "Enter in a number: ";
    cin >> board_num;

    if(!cin_good())
      continue; 

    *(p) = board_num / 10;//input validation
    if(*p < 1 || *p> 7){
      cout << endl << "Your choice must be a number between the ranges" << endl;
      continue;
    }

    *(p+1) = board_num % 10;
    if(*(p+1) < 1 || *(p+1) > 7){
      cout << endl << "Your choice must be a number between the ranges" << endl;
      continue;
    }
    correct = true;

  }while(!correct);
  
  cout << "You have chosen to move " << arr[arr_sub]  << " to " << board_num << endl;
  return arr_sub;
}


int main(){
    //char* arr used to find pieces
    const char* arr[12] = {"wK", "wQ", "wB", "wN", "wR", "wP", "bK", "bQ", "bB", "bN", "bR", "bP"};

    Player player1;
    Player player2;
    player1.set_player_number(1);
    player2.set_player_number(2);

    string pg1;
    string pg2;
    int index[3];
    int* p;
    p = index;

    bool turn = 0;
    int n = 0;
    int time_limit = 0;
    int iterations = 0;
    char start_game = '\0';
    int arr_sub;
    int choice = 0, board_num = 0;
    bool correct = false; 
    bool exit = false;
    bool finished = false;
    bool legal_move;
    bool time_limit_switch = false;

    Board board;
    board.generate_board();//generate string array board
    board.instantiate(player1, player2);//generate object array board
    
    board.show_board_init();//show the board with black and white
    endwin();

    welcome();
    
    cout << "what is the name of player 1?: ";
    cin >> player1;
    
    cout << "what is the name of player 2?: ";
    cin >> player2;
    cout << endl << "Welcome " << player1 << " and " << player2 << endl;

    start_game = '\0';
    cout << player1 << " will go first" << endl;

    cout << endl << endl << "This game will only allow you a " << endl
    << "certain amount of time in seconds to make a move " << endl
    << "After this period has expired, you will not be able " << endl
    << "to make a move. This time period has to greater than 15" << endl 
    << "seconds and less than or equal 120 seconds. " << endl << endl;

    sleep_for(10s);//giving user time to read previous output
    do{
      cout << "What would you like this time limit to be?: ";
      cin >> time_limit;
      if(!cin_good())
        continue;
      if((time_limit < 15) || (time_limit > 120)){
        cout << "Time limit is not within 15-120 seconds. Please try again!";
        continue;
      }
    }while(((time_limit < 15) || (time_limit > 120)));
    
    board.show_board_old();
    cout << endl << endl;

    auto start = chrono::steady_clock::now();
    do{
        time_limit_switch = false;
        if(iterations == 0){//asking user if they want to start game or quit
          cout << endl << "To start the game at any time, press s   \nto exit, press x: ";
          cin >> start_game;
          if(start_game =='x'){
            break;
          }
          else if (start_game !='x' && start_game !='s'){
            cout << "To start the game, you must choose s. Try again!!";
            continue;
          }else if(!cin_good()){
            continue;
          }
        }

        auto start1 = chrono::steady_clock::now();//capturing time
        auto start2 = chrono::steady_clock::now();
        if(turn == 0){//when turn = 0, it's player 1's turn
          do{
            *(p+2) = n;
            arr_sub = turns(arr, player1, p);
            auto end2 = chrono::steady_clock::now();
            if(chrono::duration_cast<chrono::seconds>(end2 - start2).count() > time_limit){//time limit checking
              cout << "You have gone over the time limit " 
              << "this turn will go to " << player2 << endl;;
              time_limit_switch = true;
              break;
            }
            
            board.search_board(arr[arr_sub]);//searching for piece in board
            
            cout << "\nThe indices are: " << index[0] << " and " << index[1] << endl;;

            legal_move = board.move_piece(index[0] - 1, index[1] - 1, 'w');
            if(!legal_move)
              continue;

          }while(!legal_move);
          n = 6;
          turn = 1;
        }else{//player 2 turn
          do{
            *(p+2) = n;
            arr_sub = turns(arr, player2, p);
            auto end2 = chrono::steady_clock::now();
            if(chrono::duration_cast<chrono::seconds>(end2 - start2).count() > time_limit){//time limit checking
              cout << "You have gone over the time limit" 
              << "this turn will go to " << player1;
              time_limit_switch = true;
              break;
            }

            board.search_board(arr[arr_sub]);//searching for piece in board

            cout << "\nThe indices are: " << index[0] << " and " << index[1] << endl;

            legal_move = board.move_piece(index[0] - 1, index[1] - 1,'b');
            if(!legal_move)
              continue;
          }while(!legal_move);
          n = 0;
          turn = 0;
        }
        if(time_limit_switch){
          continue;
        }

        endwin();
        cin.clear();
        board.show_board_old();
        
        auto end1 = chrono::steady_clock::now();
        int time_s = chrono::duration_cast<chrono::seconds>(end1 - start1).count();//time used to make move

        cout << endl << "Elapsed time in seconds: " << time_s << endl;

        if(turn == 0){
          board.update_player(time_s, player1);
        }else{
          board.update_player(time_s, player2);
        }

        if(player1.get_num_pieces() <= 0){
          cout << player2 << " wins the game";
          finished = true;
        }else if(player2.get_num_pieces() <= 0){
          cout << player1 << " wins the game";
          finished = true;
        }
        iterations++;

    }while(!finished);

    auto end = chrono::steady_clock::now();
    auto i = chrono::duration_cast<chrono::seconds>(end - start).count();//time used for whole game
    cout << endl << "This game was played for " << i << " seconds." << endl;
    sleep_for(2s);
    cout << endl << "It had " << iterations << " iterations and " << Player::get_total_moves() << " player moves " << endl;
    sleep_for(2s);
    cout << "The final board looked like: " << endl;
    sleep_for(2s);
    board.show_board();
    cout << endl << endl << "Bye!";

    sleep_for(1s);
    endwin();
    clear();
    return 0;
}
IMPORTANT:
compile using -lncurses
e.g. g++ *.cpp -lncurses 


•	The objective of the game is to destroy all the other player’s pieces. 
	Each player will start off with 6 pieces (a King, Queen, Rook, Bishop, Knight, and a Pawn). 
•	Each type of piece has its own attributes (hit points (HP), attack points (AP), and mana points (MP)) and special ability. 
•	The pawn has the ability to upgrade to a non-pawn piece if they reach the other side of the board. 
•	The pieces will move across the chess board as they do in a normal chess game. 

•	When an enemy player’s piece in the line of movement of the another, they can attack that piece. 
	If the piece that is attacked is not destroyed, the attacking piece will not move from its position. 
	The attacking piece will only move is the spot is requested is legal and empty or legal and a piece is being destroyed. 

•	If a piece loses all of its HP, it gets destroyed. A piece gains mana by attacking other pieces. 
	When the piece reaches 100 mana, they activate their special attack. 
	This will stay on for the rest of the game.

•	Pieces gain 25 mana from attacking another piece.
•	The board is a 6-by-6 board instead of a normal 8-by-8 chess board. 
	Each player will have their pieces lined up on opposite ends of the 
	chess board in the order (King, Queen, Bishop, Knight, Rook, Pawn) 
	for white and opposite for black.  

•	One player will have black pieces (denoted with a ‘b’ character in front of the abbreviated piece name, 
	the other will have white pieces (denoted with a ‘b’ character). 
•	Player 1 will start first. Each player will have a certain time decided by the players at the beginning of the game. 
	If a player doesn’t make a move within that time, they forfeit their turn. 

•	The game continues unless one player wants to forfeit at the beginning or has all their pieces destroyed. 
•	At the end of the game, the player will be able to see how much time they took for each move, how many moves they made, 
	how many moves were made during the game, what pieces they moved, and the attributes associated with those pieces.

•	The board will be setup as shown above. Player 1 will be white; Player 2 will be black. When making moves, 
	players will only be able to see a text-based version of this board. This board will only show after players make their moves

•	The players will choose the piece they want to move by typing a number into the console when prompted and then type a 
	2-digit index where they want to move on the board. The first index controls up or down and the second index controls left or right.
•	Once the game over, the last board update will be shown and the player who still has pieces on the board will have won. 


IMPORTANT:
compile using -lncurses
e.g. g++ *.cpp -lncurses 
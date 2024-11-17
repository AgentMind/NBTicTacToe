#ifndef NBTicTacToe_Assignment
#define NBTicTacToe_Assignment

#include "Coordinate.h"


class NBTicTacToe { 
    public:
        int play();
        bool getXMove(int&, int&);
        bool getOMove(int&, int&);
		void displayBoards(TicTacToe grid[3][3]);
		void valuesBoard();
        void switchBoard(Coordinate &currentBoard);
		int turnCounter;

		NBTicTacToe(int x, int y){
			srand(time(0));
			currentBoard.x = rand() % 3;
			currentBoard.y = rand() % 3;
			turnCounter = 0; 
		}
    private:
        TicTacToe board; 
		TicTacToe grid[3][3];
		Coordinate currentBoard;
};

int NBTicTacToe::play() { // My main function, runs the game 

	int player = 1;
	int done = 0;
	
	displayBoards(this->grid); //Displays intial board 
	
	while (done == 0 || done == 2) { //The game will continue through this while loop. 

		if(player != 1){ 
			cout << "Player O enter move: ";
			char playerSymbol = 'O';
		}
		else {
			char playerSymbol = 'X';
		}
		
		int x, y;
		
		if(player == 1){ //Switches between players 
			getXMove(x, y);
		}
		else{
			getOMove(x, y);
		}
		
		grid[currentBoard.x][currentBoard.y].addMove(x, y, player); //Adds the player to the grid
		turnCounter++;
		grid[currentBoard.x][currentBoard.y].setNoMoves(grid[currentBoard.x][currentBoard.y].getNoMoves() + 1); //Increment noOfMoves
		displayBoards(this->grid); //Displays board 
	
		done = grid[currentBoard.x][currentBoard.y].gameStatus(); //Checks if the game is done or not 
		if (done == 1) {
			cout << "Player X wins!" << endl;
			return 1;
		} else if (done == -1) {
			cout << "Player O wins!" << endl;
			return -1;
		} else if (turnCounter >= 81) {
			cout << "Draw game!" << endl;
			return 0;
		}

		if (player == 1)
			player = -1;
		else
			player = 1;

		if (grid[x][y].getNoMoves() >= 9) {//Switches currentBoard if full 
            switchBoard(currentBoard);
        } else {
            currentBoard.x = x;
            currentBoard.y = y;
        }

		cout << "current board is " << currentBoard.x + 1 <<  " , "  <<  currentBoard.y + 1 << endl;
		cout << "-------------------------------------------------------------------------------------------------------\n";
	}

	return 0;
}

void NBTicTacToe::switchBoard(Coordinate &currentBoard) { //Switches currentBoard when full 
    int x, y;

    do {
        x = rand() % 3;
        y = rand() % 3;
    } while (!(grid[x][y].getNoMoves() < 9));
	
    currentBoard.x = x;
    currentBoard.y = y;
}

bool NBTicTacToe::getXMove(int &x, int &y){ //Get random Player move
	srand(time(0));
	
	int row, col;

	do{
	row = (rand() % 3);
	col = (rand() % 3);
	} while (!grid[currentBoard.x][currentBoard.y].isValidMove(row,col)); //Checks if the space is valid 
	
	x = row;
	y = col;

	return true;
}

bool NBTicTacToe::getOMove(int &x, int &y) { //Get player move
	if (grid[currentBoard.x][currentBoard.y].noOfMoves >= 9)									
		return false;											
																	
	int row, col;
	do {
		cin >> row >> col;
		cout << endl;
	} while (!grid[currentBoard.x][currentBoard.y].isValidMove(row - 1, col - 1)); //Checks if the space is valid 
	x = row - 1;
	y = col - 1;

	return true;
}

void NBTicTacToe::displayBoards(TicTacToe grid[3][3]){ // Displays 9 by 9 board 

	for(int arrayRow = 0; arrayRow < 3; arrayRow++){
		
		cout << endl;

		for(int fullRow = 0; fullRow < 3; fullRow++){
			

			for(int coloumn = 0; coloumn < 3; coloumn++){
				
				grid[arrayRow][coloumn].valueBoard(fullRow);
			}
			cout << endl;
		}
	}
}

#endif 

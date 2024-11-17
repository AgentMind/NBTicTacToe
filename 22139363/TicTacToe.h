#ifndef TICTACTOE_Assignment
#define TICTACTOE_Assignment

const int BOARDSIZE = 9;

class TicTacToe { 
private:
	int board[BOARDSIZE][BOARDSIZE]; 
public:
	TicTacToe();
	bool isValidMove(int, int);
	void addMove(int, int, int);
	int gameStatus();
	int noOfMoves;
	void valueBoard(int fullRow);
	int getNoMoves();
	void setNoMoves(int);
};

int TicTacToe::getNoMoves(){ //This and setNoMoves work to get the set the noOfMoves, so we can use in NBTicTacToe
	return noOfMoves;
}

void TicTacToe::setNoMoves(int Moves){
	noOfMoves = Moves;
}

TicTacToe::TicTacToe() {  // Class constructor, intialises my noOfMoves to 0, and sets up the values in boards spaces to 0, so its empty 
	for (int row = 0; row < 3; row++)
		for (int col = 0; col < 3; col++)
			board[row][col] = 0;

	noOfMoves = 0;

	
}

bool TicTacToe::isValidMove(int x, int y) {  // This checks if the move is within the confined bounds, and returns true or false
	if (board[x][y] == 0 && x < 3 && y < 3 && x > -1 && y > -1) 
		return true;
	else
		return false;
}

void TicTacToe::addMove(int x, int y, int player) { // Add the input of the player into the board
	board[x][y] = player;							
}

int TicTacToe::gameStatus() { //Checks the status of the game   
for(int i =0; i < 3;i++){
	if(board[i][0] == board[i][1] && board[i][2] == board[i][1] && board[1][0] != 0){
		return board[i][1];
	}
}
for(int i =0; i < 3;i++){
	if(board[0][i] == board[1][i] && board[2][i] == board[1][i] && board[0][i] != 0){
		return board[1][i];
	}
}
if(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != 0){
		return board[0][0];
}

if(board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != 0){
		return board[0][2];
}

if (noOfMoves >= 9){
		return 2;
}
return 0;
}

void TicTacToe::valueBoard(int fullRow){ //Sets the values of the grids in the board to either X, O or _ 
	char symbol = ' ';
	for (int i = 0; i < 3; i++)
	{
		if (this->board[fullRow][i] == 1)
			symbol = 'X';
		else if (this->board[fullRow][i] == -1)
			symbol = 'O';
		else
			symbol = '_';

		cout << "" << symbol << "";
		
	}
	cout << " ";
}

#endif 

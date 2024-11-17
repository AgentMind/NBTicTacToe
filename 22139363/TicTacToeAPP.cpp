/*
 * TicTacToeAPP.cpp
 *
 *  Created on: 5 Aug 2023
 *      Author: 2002345
 */
#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>

using namespace std;

#include "TicTacToe.h"
#include "NBTicTacToe.h"
#include "Coordinate.h"

int main() {
	NBTicTacToe start(0, 0); // This statement means it is creating an object called start, which belongs to the class TicTacToe
	start.play();    // It is an instance that we can use to call the class TicTacToe. 

	return 0;

}



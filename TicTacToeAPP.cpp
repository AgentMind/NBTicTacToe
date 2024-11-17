/*********** Declaration*******
I hereby certify that no part of this assignment has been copied from
any other student’s work or from any other source. No part of the
code has been written/produced for me by another person or copied
from any other source.
I hold a copy of this assignment that I can produce if the original
is lost or damaged.
**************************/

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




#include "main.h"
#include <cstdlib>
#include <vector>
#include <iterator>
#include <iostream>

int main() {
    Board board;
    board.SetAliveOnCoordinates( 1, 2 );
    board.SetAliveOnCoordinates( 5, 6 );
    std::cout << "Begin by pressing enter\n";
    board.Draw ();
    board.SetNewAliveStatuses (); 
    std::cout << "\n\n\n";
    board.Draw ();
    board.SetNewAliveStatuses (); 
}

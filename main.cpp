#include "main.h"
#include <cstdlib>
#include <vector>
#include <iterator>
#include <iostream>


int main() {
    Board board;
    board.SetAliveOnCoordinates( 1, 2 );
    board.SetAliveOnCoordinates( 2, 2 );
    board.SetAliveOnCoordinates( 2, 3 );
    board.SetAliveOnCoordinates( 2, 4 );
    board.SetAliveOnCoordinates( 5, 6 );
    std::cout << "Begin by pressing enter\n";


    for ( int i = 0; i < 10; i++ ) 
    {
        system( "sleep 2" );
        board.Draw ();
        board.CalculateNeighbours ();
        board.SetNewAliveStatuses (); 
    }
}


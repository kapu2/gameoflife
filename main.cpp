#include "main.h"
#include <cstdlib>
#include <vector>
#include <iterator>
#include <iostream>

#define MAX_STEPS 100
int main ()
{
    Board board;
    board.SetAliveOnCoordinates( 2, 6 );
    board.SetAliveOnCoordinates( 2, 7 );
    board.SetAliveOnCoordinates( 3, 6 );
    board.SetAliveOnCoordinates( 3, 7 );
    board.SetAliveOnCoordinates( 12, 6 );
    board.SetAliveOnCoordinates( 12, 7 );
    board.SetAliveOnCoordinates( 12, 8 );
    board.SetAliveOnCoordinates( 13, 5 );
    board.SetAliveOnCoordinates( 13, 9 );
    board.SetAliveOnCoordinates( 14, 4 );
    board.SetAliveOnCoordinates( 14, 10 );
    board.SetAliveOnCoordinates( 15, 4 );
    board.SetAliveOnCoordinates( 15, 10 );
    board.SetAliveOnCoordinates( 16, 7 );
    board.SetAliveOnCoordinates( 17, 5 );
    board.SetAliveOnCoordinates( 17, 9 );
    board.SetAliveOnCoordinates( 18, 6 );
    board.SetAliveOnCoordinates( 18, 7 );
    board.SetAliveOnCoordinates( 18, 8 );
    board.SetAliveOnCoordinates( 19, 7 );
    board.SetAliveOnCoordinates( 22, 5 );
    board.SetAliveOnCoordinates( 22, 6 );
    board.SetAliveOnCoordinates( 22, 7 );
    board.SetAliveOnCoordinates( 23, 5 );
    board.SetAliveOnCoordinates( 23, 6 );
    board.SetAliveOnCoordinates( 23, 7 );
    board.SetAliveOnCoordinates( 24, 5 );
    board.SetAliveOnCoordinates( 24, 8 );
    board.SetAliveOnCoordinates( 26, 4 );
    board.SetAliveOnCoordinates( 26, 5 );
    board.SetAliveOnCoordinates( 26, 8 );
    board.SetAliveOnCoordinates( 26, 9 );
    board.SetAliveOnCoordinates( 36, 4 );
    board.SetAliveOnCoordinates( 36, 5 );
    board.SetAliveOnCoordinates( 37, 4 );
    board.SetAliveOnCoordinates( 37, 5 );
    std::cout << "Begin by pressing enter\n";

    
    for ( int i = 0; i < MAX_STEPS; i++ ) 
    {
        system( "sleep 1" );
        board.Draw ();
        board.CalculateNeighbours ();
        board.SetNewAliveStatuses (); 
    }
    return 0;
}

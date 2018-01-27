#include "Board.h"
#include "Life.h"
#include <cstdlib>
#include <vector>
#include <iterator>
#include <iostream>


Board::Board()
{
    for ( int y = 0; y < HEIGHT; ++y ) 
    {
        std::vector<Life> inner_lives;
        for ( int x = 0; x < WIDTH; ++x )
        {
            Life* life = new Life( x, y );
            inner_lives.push_back ( *life );
        }
        lives.push_back ( inner_lives );
    }
}

Board::~Board()
{
    // TODO: memory will be not freed for objects
}

bool Board::Draw()
{
    for ( std::vector< std::vector<Life> >::iterator row = lives.begin(); row != lives.end(); ++row )
    {
        for ( std::vector<Life>::iterator column = row->begin(); column != row->end(); ++column )
        {
            std::cout << column->GetAliveStatus();
        }
        std::cout << "\n";
    }
    return 1;
}

void Board::SetNewAliveStatuses()
{
    for ( std::vector< std::vector<Life> >::iterator row = lives.begin(); row != lives.end(); ++row )
    {
        for ( std::vector<Life>::iterator column = row->begin(); column != row->end(); ++column )
        {
            column->CheckAliveStatus();
        }
    }
}

void Board::SetAliveOnCoordinates( int x, int y )
{
    lives[y][x].CheckAliveStatus( 1 );
}



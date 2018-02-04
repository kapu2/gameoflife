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
    system( "clear" );
    for ( std::vector< std::vector<Life> >::iterator row = lives.begin(); row != lives.end(); ++row )
    {
        for ( std::vector<Life>::iterator column = row->begin(); column != row->end(); ++column )
        {
            if ( column->GetAliveStatus() )
            {
                std::cout << "1";
            }
            else
            {
                std::cout << "_";
            }
            //std::cout << column->GetNeighbourAmount();
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

void Board::CalculateNeighbours()
{
   for ( int y = 0; y < HEIGHT; ++y )
   {
        for ( int x = 0; x < WIDTH; ++x )
        {
            lives[y][x].SetNeighbourAmount( 0 );
        }
   }
   for ( int y = 0; y < HEIGHT; ++y )
   {
        for ( int x = 0; x < WIDTH; ++x )
        {
            if ( y != HEIGHT - 1 )
            {
                lives[y + 1][x].SetNeighbourAmount( lives[y + 1][x].GetNeighbourAmount() + lives[y][x].GetAliveStatus() );
            }
            if ( y != 0 )
            {
                lives[y - 1][x].SetNeighbourAmount( lives[y - 1 ][x].GetNeighbourAmount() + lives[y][x].GetAliveStatus() );
            }
            if ( x != WIDTH - 1 )
            {
                lives[y][x + 1].SetNeighbourAmount( lives[y][x + 1].GetNeighbourAmount() + lives[y][x].GetAliveStatus() );
            }
            if ( x != 0 )
            {
                lives[y][x - 1].SetNeighbourAmount( lives[y][x - 1].GetNeighbourAmount() + lives[y][x].GetAliveStatus() );
            }
        }
   }
}

void Board::SetAliveOnCoordinates( int x, int y )
{
    lives[y][x].CheckAliveStatus( 1 );
}



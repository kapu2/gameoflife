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
        std::vector<Life*> inner_lives;
        for ( int x = 0; x < WIDTH; ++x )
        {
            Life* life = new Life( x, y );
            inner_lives.push_back ( life );
        }
        lives.push_back ( inner_lives );
    }
}

Board::~Board()
{
    for ( int y = 0; y < HEIGHT; ++y ) 
    {
        for ( int x =0; x < WIDTH; ++x )
        {
            delete lives[y][x];
        }
    }
}

bool Board::Draw()
{
    system( "clear" );
    for ( std::vector< std::vector<Life*> >::iterator row = lives.begin(); row != lives.end(); ++row )
    {
        for ( std::vector<Life*>::iterator column = row->begin(); column != row->end(); ++column )
        {
            if ( (*column)->GetAliveStatus () )
            {
                std::cout << "1";
            }
            else
            {
                std::cout << "_";
            }
        }
        std::cout << "\n";
    }
    return 1;
}

void Board::SetNewAliveStatuses ()
{
    for ( std::vector< std::vector<Life*> >::iterator row = lives.begin (); row != lives.end (); ++row )
    {
        for ( std::vector<Life*>::iterator column = row->begin (); column != row->end (); ++column )
        {
            (*column)->CheckAliveStatus ();
        }
    }
}

void Board::CalculateNeighbours()
{
   for ( int y = 0; y < HEIGHT; ++y )
   {
        for ( int x = 0; x < WIDTH; ++x )
        {
            lives[y][x]->SetNeighbourAmount( 0 );
        }
   }
   for ( int y = 0; y < HEIGHT; ++y )
   {
        for ( int x = 0; x < WIDTH; ++x )
        {
            // Not bottom
            if ( y != HEIGHT - 1 )
            {
                lives[y + 1][x]->SetNeighbourAmount( lives[y + 1][x]->GetNeighbourAmount() + lives[y][x]->GetAliveStatus() );
            }
            // Not top
            if ( y != 0 )
            {
                lives[y - 1][x]->SetNeighbourAmount( lives[y - 1 ][x]->GetNeighbourAmount() + lives[y][x]->GetAliveStatus() );
            }
            // Not right edge
            if ( x != WIDTH - 1 )
            {
                lives[y][x + 1]->SetNeighbourAmount( lives[y][x + 1]->GetNeighbourAmount() + lives[y][x]->GetAliveStatus() );
            }
            // Not left edge
            if ( x != 0 )
            {
                lives[y][x - 1]->SetNeighbourAmount( lives[y][x - 1]->GetNeighbourAmount() + lives[y][x]->GetAliveStatus() );
            }
            // Not upper left corner
            if ( ( x != 0 ) && ( y != 0 ) ) 
            {
                lives[y - 1][x - 1]->SetNeighbourAmount( lives[y - 1][x - 1]->GetNeighbourAmount() + lives[y][x]->GetAliveStatus() );
            }
            // Not upper right corner
            if ( ( x != WIDTH -1 ) && ( y != 0 ) )
            {
                lives[y - 1][x + 1]->SetNeighbourAmount( lives[y - 1][x + 1]->GetNeighbourAmount() + lives[y][x]->GetAliveStatus() );
            }
            // Not bottom right corner
            if ( ( x != WIDTH -1 ) && ( y != HEIGHT - 1 ) )
            {
                lives[y + 1][x + 1]->SetNeighbourAmount( lives[y + 1][x + 1]->GetNeighbourAmount() + lives[y][x]->GetAliveStatus() );
            }
            // Not bottom left corner
            if ( ( x != 0 ) && ( y != HEIGHT - 1 ) )
            {
                lives[y + 1][x - 1]->SetNeighbourAmount( lives[y + 1][x - 1]->GetNeighbourAmount() + lives[y][x]->GetAliveStatus() );
            }
        }
   }
}

void Board::SetAliveOnCoordinates( int x, int y )
{
    lives[y][x]->CheckAliveStatus( 1 );
}



#include "Board.h"
#include <cstdlib>
#include <vector>
#include <iterator>
#include <iostream>

Board::Board()
{
    int i;
    for ( i = 0; i < 20; ++i ) 
    {
        coordinates.push_back ( std::vector<bool> ( 20, 0 ) );
    }

}

Board::~Board()
{
}

bool Board::Draw()
{
    for ( std::vector< std::vector<bool> >::iterator row = coordinates.begin(); row != coordinates.end(); ++row )
    {
        for ( std::vector<bool>::iterator column = row->begin(); column != row->end(); ++column )
        {
            std::cout << *column;
        }
        std::cout << "\n";
    }
}

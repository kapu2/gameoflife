#include "Life.h"
#include <iostream>

Life::Life( int x, int y )
{
    x_coord = x;
    y_coord = y;
    neighbours = 0;
    alive = 0;
}

Life::~Life()
{
}

int Life::GetXLocation()
{
    return x_coord;
}

int Life::GetYLocation()
{
    return y_coord;
}

void Life::CheckAliveStatus()
{
    if ( ( neighbours == 2 ) && ( alive ) )
    {
        // Do nothing
    }
    else if ( neighbours == 3 )
    {
        alive = 1;
    }
    else
    {
        alive = 0;
    }
}

void Life::SetNeighbourAmount( int neighbour_amount )
{
    neighbours = neighbour_amount;
}

int Life::GetNeighbourAmount()
{
    return neighbours;
}

void Life::CheckAliveStatus( bool initial_alive_status )
{
    alive = initial_alive_status;
}

bool Life::GetAliveStatus()
{
    return alive;
}

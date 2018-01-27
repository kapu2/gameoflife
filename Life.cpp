#include "Life.h"

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
    if ( ( neighbours > 1 ) || ( neighbours < 4 ) )
    {
        alive = 1;
    }
    else
    {
        alive = 0;
    }
}

void Life::CheckAliveStatus( bool initial_alive_status )
{
    alive = initial_alive_status;
}

bool Life::GetAliveStatus()
{
    return alive;
}

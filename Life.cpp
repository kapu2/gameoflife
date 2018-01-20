#include "Life.h"

Life::Life( int x, int y )
{
    x_coord = x;
    y_coord = y;
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
}

bool Life::GetAliveStatus()
{
}

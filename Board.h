#include "Life.h"
#include <cstdlib>
#include <vector>
#include <iterator>
#include <iostream>
#define WIDTH 20
#define HEIGHT 20

#ifndef BOARD_H
#define BOARD_H
class Board
{
    private:
        std::vector< std::vector<Life> > lives;

    public:
        Board();
        ~Board();
        bool Draw();
        void SetAliveOnCoordinates( int x, int y );
        void SetNewAliveStatuses();
};
#endif

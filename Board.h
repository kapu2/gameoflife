#include <cstdlib>
#include <vector>
#include <iterator>
#include <iostream>

#ifndef BOARD_H
#define BOARD_H
#define WIDTH 20;
#define HEIGHT 20;
class Board
{
    private:
        int GetSymbol();
        std::vector< std::vector<bool> > coordinates;

    public:
        Board();
        ~Board();
        bool Draw();
};
#endif

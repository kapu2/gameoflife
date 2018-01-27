#ifndef LIFE_H
#define LIFE_H
class Life
{
    public:
        Life( int x, int y );
        ~Life();
        int GetXLocation();
        int GetYLocation();
        void CheckAliveStatus();
        void CheckAliveStatus( bool initial_alive_status );
        bool GetAliveStatus();
    private:
        int x_coord;
        int y_coord;
        bool alive;
        int neighbours;
};
#endif

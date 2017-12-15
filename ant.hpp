#ifndef ANT_HPP
#define ANT_HPP
#include "map.hpp"

#define TOP 0
#define LEFT 1
#define DOWN 2
#define RIGHT 3
#define TURN_LEFT(dir) ((dir + 1) % 4)
#define TURN_RIGHT(dir) ((dir + 3) % 4)
#define DX(dir) (dir & 0b1 ? dir - 2 : 0)
#define DY(dir) (dir & 0b1 ? 0 : dir - 1)

class Ant {
    public:
        Ant(int, int);
        ~Ant();
        void update(Map&);

    private:
        char m_direction;
        int m_x;
        int m_y;
};

#endif // ANT_HPP

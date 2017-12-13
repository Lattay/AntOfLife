#ifndef ANT_HPP
#define ANT_HPP
#include "map.hpp"

class Ant {
    public:
        Ant(int, int);
        void update(Map&);

    private:
        char m_direction;
        int m_x;
        int m_y;
};

#endif // ANT_HPP

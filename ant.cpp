#include "ant.hpp"

Ant::Ant(int x, int y):
    m_direction(TOP), m_x(x), m_y(y)
{
}

Ant::~Ant(){};

void Ant::update(Map &map){
    if(map.get_cell(m_x, m_y) == ALIVE){
       m_direction = TURN_LEFT(m_direction);
    } else {
        m_direction = TURN_RIGHT(m_direction);
    }
    map.switch_cell(m_x, m_y);
    m_x += DX(m_direction);
    m_y += DY(m_direction);

}

int Ant::get_x(){
    return m_x;
}

int Ant::get_y(){
    return m_y;
}

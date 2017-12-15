#include "ant.hpp"
#include <iostream>

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
    std::cout << m_x << " " << m_y << std::endl;

}
    

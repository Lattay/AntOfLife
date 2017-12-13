#include "window.hpp"

AOLWindow::AOLWindow(int w, int h, std::string name) : 
    sf::RenderWindow(sf::VideoMode(w, h), name), m_w(w), m_h(h)
{

}

AOLWindow::~AOLWindow(){}

void AOLWindow::draw_map(Map &map){
    int wc = map.get_w(), hc = map.get_h();
    int wr = m_w / wc, hr = m_h / hc;
    sf::RectangleShape cell(sf::Vector2f(wr, hr));

    Swvec switched = map.get_switched();
    for(int i = 0, s = switched.size(); i < s; i++){
        cell.setPosition(wr*switched[i].x, hr*switched[i].y);
        if(switched[i].state == ALIVE){
            cell.setFillColor(sf::Color(255,255,255));
        } else if(switched[i].state == DEAD){
            cell.setFillColor(sf::Color(0,0,0));
        }
        draw(cell);
    }
}

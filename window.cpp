#include "window.hpp"
#include <iostream>

AOLWindow::AOLWindow(int w, int h, std::string name) : 
    sf::RenderWindow(sf::VideoMode(w, h), name), m_w(w), m_h(h)
{

}

AOLWindow::~AOLWindow(){}

void AOLWindow::apply_resize(int w, int h){
    m_w = w;
    m_h = h;
}

void AOLWindow::first_draw(Map &map){
    int wc = map.get_w(), hc = map.get_h();
    float wr = float(m_w) / float(wc), hr = float(m_h) / float(hc);

    sf::RectangleShape cell(sf::Vector2f(wr, hr));
    for(int x = 0; x < wc; x++){
        for(int y = 0; y < hc; y++){
            cell.setPosition(wr*x, hr*y);
            if(map.get_cell(x, y) == ALIVE){
                cell.setFillColor(CLR_ALIVE);
            } else {
                cell.setFillColor(CLR_DEAD);
            }
            draw(cell);
        }
    }
}

void AOLWindow::draw_map(Map &map){
    int wc = map.get_w(), hc = map.get_h();
    float wr = float(m_w) / float(wc), hr = float(m_h) / float(hc);

    sf::RectangleShape cell(sf::Vector2f(wr, hr));
    Swvec switched = map.get_switched();
    for(int i = 0, s = switched.size(); i < s; i++){
        cell.setPosition(wr*switched[i].x, hr*switched[i].y);
        if(switched[i].state == ALIVE){
            cell.setFillColor(CLR_ALIVE);
        } else if(switched[i].state == DEAD){
            cell.setFillColor(CLR_DEAD);
        }
        draw(cell);
    }
}

#if !EDITOR_MODE
void AOLWindow::draw_ant(Map &map, Ant &ant){
    int wc = map.get_w(), hc = map.get_h();
    float wr = float(m_w) / float(wc), hr = float(m_h) / float(hc);

    int x = ant.get_x();
    int y = ant.get_y();
    if(x >= 0 && x < wc && y >= 0 && y < hc){
        sf::RectangleShape cell(sf::Vector2f(wr, hr));
        cell.setPosition(wr*x, hr*y);
        cell.setFillColor(CLR_ANT);
        draw(cell);
    }
}
#endif // EDITOR_MODE

int AOLWindow::get_wc(Map &map){
    return int(float(m_w) / float(map.get_w()));
}

int AOLWindow::get_hc(Map &map){
    return int(float(m_h) / float(map.get_h()));
}


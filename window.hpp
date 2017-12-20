#ifndef WINDOW_HPP
#define WINDOW_HPP
#include <SFML/Graphics.hpp>
#include <string>
#include "map.hpp"
#include "ant.hpp"

#define CLR_ALIVE sf::Color(0,255,80)
#define CLR_DEAD sf::Color(0,25,50)
#define CLR_ANT sf::Color(200,50,0)

class AOLWindow: public sf::RenderWindow
{
    public:
        AOLWindow(int, int, std::string);
        ~AOLWindow();
        void apply_resize(int, int);
        void first_draw(Map&);
        void draw_map(Map&);
        void draw_ant(Map&, Ant&);
        int get_wc(Map&);
        int get_hc(Map&);

    private:
        int m_w;
        int m_h;
        
};

#endif // WINDOW_HPP

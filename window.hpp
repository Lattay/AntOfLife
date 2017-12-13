#ifndef WINDOW_HPP
#define WINDOW_HPP
#include <SFML/Graphics.hpp>
#include <string>
#include "map.hpp"

class AOLWindow: public sf::RenderWindow
{
    public:
        AOLWindow(int, int, std::string);
        ~AOLWindow();
        void first_draw(Map&);
        void draw_map(Map&);

    private:
        int m_w;
        int m_h;
        
};

#endif // WINDOW_HPP

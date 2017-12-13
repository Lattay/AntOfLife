#include <iostream>
#include <string>
#include "map.hpp"
//#include "ant.hpp"
#include "window.hpp"

#define SIZEX 800
#define SIZEY 800

int main(int argc, char** argv){
    std::cout << "Initialisation of the field..." << std::endl;
    Map map("test.txt");
    //Ant ant(SIZEX/2, SIZEY/2);
    std::cout << "Creating the window..." << std::endl;
    AOLWindow window(SIZEX, SIZEY, std::string("Ant of Life"));
    std::cout << "Window created." << std::endl;

    window.first_draw(map);
    
    window.display();
    while (window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                window.close();
            }

        }


        //window.clear();
        window.draw_map(map);
        window.display();
        map.update();
        //ant.update(map);
    }

    return 0;
}

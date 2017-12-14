#include <iostream>
#include <string>
#include "map.hpp"
//#include "ant.hpp"
#include "window.hpp"

#define SIZEX 480
#define SIZEY 280

int main(int argc, char** argv){
    std::cout << "Initialisation of the field..." << std::endl;

    Map map("test.txt");

    sf::Time T = sf::milliseconds(1000);

    //Ant ant(SIZEX/2, SIZEY/2);
    
    std::cout << "Creating the window..." << std::endl;
    AOLWindow window(SIZEX, SIZEY, std::string("Ant of Life"));
    std::cout << "Window created." << std::endl;

    window.first_draw(map);
    
    window.display();

    sf::Clock timer;
    while (window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                window.close();
            }

        }


        //window.clear();
        if(timer.getElapsedTime() > T){
            map.update();
            //ant.update(map);
            window.draw_map(map);
            window.display();
            timer.restart();
        }
    }

    return 0;
}

#include <iostream>
#include <string>
#include "cmdline.hpp"
#include "map.hpp"
#include "ant.hpp"
#include "window.hpp"

#define SIZEX 480
#define SIZEY 280

int main(int argc, char** argv){

    Cmd cmd(argc, argv);

    if(cmd.p_state == FAIL){
        std::cout << "Unable to parse command line options." << std::endl;
        return 1;
    } else if(cmd.p_state == HELP){
        return 0;
    }


    Map* map;
    if(cmd.get_random()){
        map = new Map(cmd.get_rw(), cmd.get_rh(), cmd.get_prop());
        if(!map->gen_map()){
            std::cout << "Unable to create map." << std::endl;
            return 1;
        }
    } else {
        map = new Map(cmd.get_filename());
        if(!map->load_map()){
            std::cout << "Unable to load map file." << std::endl;
            return 1;
        }
    }

    sf::Time T = sf::milliseconds(cmd.get_T());

    Ant ant(map->get_w()/2, map->get_h()/2);
    
    std::cout << "Creating the window..." << std::endl;
    AOLWindow window(cmd.get_w(), cmd.get_h(), std::string("Ant of Life"));
    std::cout << "Window created." << std::endl;

    window.first_draw(*map);
    
    window.display();

    sf::Clock timer;
    int generation = 0;
    while (window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                window.close();
            } else if(event.type == sf::Event::Resized){
                window.resize(event.size.width, event.size.height);
                window.clear();
                window.first_draw(*map);
            }

        }


        //window.clear();
        if(timer.getElapsedTime() > T){
            if(cmd.gol_enabled()){
                map->update();
            }
            
            if(cmd.ant_enabled()){
                ant.update(*map);
            }

            window.draw_map(*map);
            window.display();
            timer.restart();
            generation++;
        }
    }

    delete map;

    std::cout << generation << " generation have been computed." << std::endl;
    return 0;
}

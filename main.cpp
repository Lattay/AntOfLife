#include <iostream>
#include <string>
#include "cmdline.hpp"
#include "map.hpp"
#include "ant.hpp"
#include "window.hpp"

#define SIZEX 480
#define SIZEY 280

int choose_cell_size(Map &map){
    int w = map.get_w();
    int h = map.get_h();
    int s = 64;
    while(w*s > 1400 || h*s > 800){
        s--;
    }
    return s > 0 ? s : 1;
}


int main(int argc, char** argv){

    Cmd cmd(argc, argv);

    if(cmd.p_state == FAIL){
        std::cout << "Unable to parse command line options." << std::endl;
        return 1;
    } else if(cmd.p_state == HELP){
        return 0;
    }


    Map* map;
    if(cmd.use_random()){
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

    bool mode_ant = cmd.ant_enabled();
    bool mode_gol = cmd.gol_enabled();

    Ant ant(map->get_w()/2, map->get_h()/2);
    
    int csize = 64;
    if(cmd.get_csize() > 0){
        csize = cmd.get_csize();
    } else {
        csize = choose_cell_size(*map);
    }

    std::cout << "Creating the window..." << std::endl;
    AOLWindow window(map->get_w()*csize, map->get_h()*csize, std::string("Ant of Life"));
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
                window.apply_resize(event.size.width, event.size.height);
                window.clear();
                window.first_draw(*map);
                if(mode_ant){
                    window.draw_ant(*map, ant);
                }
            }

        }


        //window.clear();
        if(timer.getElapsedTime() > T){
            if(mode_gol){
                map->update();
            }
            
            if(mode_ant){
                ant.update(*map);
            }

            window.draw_map(*map);
            map->clean_switched(); // important dans le mode ant

            if(mode_ant){
                window.draw_ant(*map, ant);
            }

            window.display();
            timer.restart();
            generation++;
        }
    }

    delete map;

    std::cout << generation << " generation have been computed." << std::endl;
    return 0;
}

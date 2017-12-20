#include <iostream>
#include <string>
#include "cmdline_editor.hpp"
#include "map.hpp"
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
    if(cmd.create_new()){
        map = new Map(cmd.get_nw(), cmd.get_nh(), 0);
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

    bool has_event = false;
    while (window.isOpen()){
        has_event = false;
        sf::Event event;
        while (window.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                window.close();
            } else if(event.type == sf::Event::Resized){
                window.apply_resize(event.size.width, event.size.height);
                window.clear();
                window.first_draw(*map);
            } else if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left){
                int x = event.mouseButton.x / window.get_wc(*map);
                int y = 1 + event.mouseButton.y / window.get_hc(*map);
                map->switch_cell(x, y);
            }
            has_event = true;
        }


        if(has_event){
            window.draw_map(*map);
            map->clean_switched(); // important dans le mode ant

            window.display();
        }
    }

    // save map

    delete map;

    return 0;
}

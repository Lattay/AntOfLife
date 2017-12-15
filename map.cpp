#include <iostream>
#include "map.hpp"

Map::Map(std::string filename):
    m_w(0), m_h(0), m_nbsw(0), m_filename(filename)
{
    std::cout << "Loading map file..." << std::endl;
    load_map();
    std::cout << "Done." << std::endl;
}

Map::~Map(){}


void Map::update(){
    m_nbsw = 0;
    for(int i = 0, l = m_w*m_h; i < l; i++){
        if(m_cells[i] == ALIVE){
            char next = count_next(i);
            m_switched[i] = next != 2 && next != 3;
        } else {
            m_switched[i] = count_next(i) == 3;
        }
        if(m_switched[i]){
            m_nbsw++;
        }
    }
    for(int i = 0, l = m_w*m_h; i < l; i++){
        if(m_switched[i]){
            if(m_cells[i] == ALIVE){
                m_cells[i] = DEAD;
            } else {
                m_cells[i] = ALIVE;
            }
        }
    }
}

char Map::get_cell(int x, int y){
    return m_cells[get_index(x, y)];
}

Swvec Map::get_switched(){
    Swvec v(m_nbsw);

    int j = 0;
    for(int i = 0, l = m_w*m_h; i < l; i++){
        if(m_switched[i]){
            v[j++] = {.x = get_x(i), .y = get_y(i), .state = m_cells[i]};
        }
    }


    return v;
}

int Map::get_w(){
    return m_w;
}

int Map::get_h(){
    return m_h;
}

void Map::load_map(){
    std::ifstream file;
    file.open(m_filename);
    int nw = 0;
    char c = 'x';
    
    file.seekg (0, file.end);
    int l = file.tellg();
    file.seekg (0, file.beg);

    char* buffer = new char[l];
    
    file.read(buffer, l);
    file.close();

    for(int i = 0; i < l; i++){
        c = buffer[i];
        if(c == '\n'){
            if(nw > m_w){
                m_w = nw;
            }
            nw = 0;
            m_h += 1;
        } else {
            nw += 1;
        }
    }

    m_cells = std::vector<char>(m_h*m_w);
    m_switched = std::vector<bool>(m_h*m_w, false);
    
    c = 'x';
    int x = 0;
    int y = 0;
    for(int i = 0; i < l; i++){
        c = buffer[i];
        if(c == '\n'){
            y += 1;
            x = 0;
        } else {
            if(c == '*'){
                m_cells[get_index(x, y)] = ALIVE;
            } else {
                m_cells[get_index(x, y)] = DEAD;
            }
            x += 1;
        }
    }
    delete[] buffer;
}


#define check_and_add(i) if(i >= 0 && i < l){if(m_cells[i]){c++;}}
int Map::count_next(int i){
    int c = 0;
    int l = m_w*m_h;
    check_and_add(i + m_w)
    check_and_add(i + 1)
    check_and_add(i + m_w + 1)
    check_and_add(i - m_w)
    check_and_add(i - 1)
    check_and_add(i - m_w - 1)
    check_and_add(i - m_w + 1)
    check_and_add(i + m_w - 1)
    return c;
}

/*
int Map::count_next(int x, int y){
    return m_cells[get_index(x, y + 1)] + 
        m_cells[get_index(x, y + 1)] +
        m_cells[get_index(x - 1, y + 1)] +
        m_cells[get_index(x - 1, y)] +
        m_cells[get_index(x - 1, y - 1)] +
        m_cells[get_index(x - 1, y - 1)] +
        m_cells[get_index(x, y - 1)] +
        m_cells[get_index(x + 1, y - 1)];
}
*/

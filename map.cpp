#include <iostream>
#include "map.hpp"

Map::Map(std::string filename):
    m_filename(filename), m_w(0), m_h(0)
{
    load_map();
}

Map::~Map(){}


void Map::update(){
    for(int i = 0, l = m_w*m_h; i < l; i++){
        if(m_cells[i] == ALIVE){
            char next = count_next(i);
            m_switched[i] = next != 2 && next != 3;
        } else {
            m_switched[i] = count_next(i) == 3;
        }
    }
}

char Map::get_cell(int x, int y){
    return m_cells[get_index(x, y)];
}

Swvec Map::get_switched(){
    int c = 0;

    for(int i = 0, l = m_w*m_h; i < l; i++){
        if(m_switched[i])
            c++;
    }

    Swvec v(c);

    for(int i = 0, l = m_w*m_h; i < l; i++){
        if(m_switched[i])
            v[i] = {get_x(i), get_y(i), m_cells[i]};
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
    while(c != EOF){
        c = file.get();
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
    m_switched = std::vector<bool>(m_h*m_w);
    
    c = 'x';
    int x = 0;
    int y = 0;
    while(c != EOF){
        c = file.get();
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
    file.close();
}


int Map::count_next(int i){
    return m_cells[i + m_w] +
        m_cells[i + 1] +
        m_cells[i + m_w + 1] +
        m_cells[i - m_w] +
        m_cells[i - 1] +
        m_cells[i - m_w - 1] +
        m_cells[i - m_w + 1] +
        m_cells[i + m_w - 1];
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

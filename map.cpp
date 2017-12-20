#include <iostream>
#include "map.hpp"

/*
#define echo std::cout <<
#define esp << " " <<
#define nl << std::endl
*/

Map::Map(std::string filename):
    m_w(0), m_h(0), m_prop(-1), m_nbsw(0), m_filename(filename)
{
}

Map::Map(int w, int h, float prop):
    m_w(w), m_h(h), m_prop(prop), m_nbsw(0), m_filename("")
{
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
    if(x >= 0 && x < m_w && y >= 0 && y < m_h)
        return m_cells[get_index(x, y)];
    return DEAD;
}

void Map::switch_cell(int x, int y){
    if(x >= 0 && x < m_w && y >= 0 && y < m_h){
        int i = get_index(x, y);
        if(!m_switched[i]){
            m_cells[i] = m_cells[i] == ALIVE ? DEAD : ALIVE;
            m_switched[i] = true;
            m_nbsw++;
        }
    }
}



Swvec Map::get_switched(){
    Swvec v(m_nbsw);

    for(int i = 0, j = 0, l = m_w*m_h; i < l; i++){
        if(m_switched[i]){
            v[j++] = {.x = GET_X(i), .y = GET_Y(i), .state = m_cells[i]};
        }
    }

    return v;
}

void Map::clean_switched(){
    for(int i = 0, l = m_w*m_h; i < l; i++){
        m_switched[i] = false;
    }
}

int Map::get_w(){
    return m_w;
}

int Map::get_h(){
    return m_h;
}

bool Map::load_map(){
    if(m_prop != -1){
        return false;
    }
    std::ifstream file;
    file.open(m_filename);
    if(!file.is_open()){
        return false;
    }
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
        } else if(c == '\r'){
            // ignore
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
        } else if(c == '\r'){
            // ignore
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
    return true;
}

bool Map::gen_map(){
    if(m_prop < 0){
        return false;
    }
    
    std::random_device generator;
    std::bernoulli_distribution dist(m_prop);
    
    m_cells = std::vector<char>(m_h*m_w);
    m_switched = std::vector<bool>(m_h*m_w, false);
    for(int i = 0, l = m_h*m_w; i < l; i++){
        float r = dist(generator);
        if(r){
            m_cells[i] = ALIVE;
        } else {
            m_cells[i] = DEAD;
        }
    }   
    return true;
}

#define check_and_add(x, y, i) if(x >= 0 && x < m_w && y >= 0 && y < m_h){if(m_cells[i] == ALIVE){c++;}}

int Map::count_next(int i){
    int c = 0;
    int x = GET_X(i);
    int y = GET_Y(i);

    check_and_add(x, y + 1, i + m_w)
    check_and_add(x + 1, y, i + 1)
    check_and_add(x + 1, y + 1, i + m_w + 1)
    check_and_add(x, y - 1, i - m_w)
    check_and_add(x - 1, y, i - 1)
    check_and_add(x - 1, y - 1, i - m_w - 1)
    check_and_add(x + 1, y - 1, i - m_w + 1)
    check_and_add(x - 1, y + 1, i + m_w - 1)
    return c;
}

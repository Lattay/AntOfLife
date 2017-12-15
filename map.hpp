#ifndef MAP_HPP
#define MAP_HPP
#include <string>
#include <vector>
#include <fstream>
#include <random>

#define ALIVE 1
#define DEAD 0

#define get_index(x, y) (m_w * y + x)
#define get_x(i) i % m_w
#define get_y(i) i / m_w


struct Switched {
    int x;
    int y;
    char state;
};

typedef std::vector<Switched> Swvec;

class Map
{
    public:
        Map(std::string);
        Map(int, int, float);
        ~Map();
        bool load_map();
        bool gen_map();
        void update();
        char get_cell(int, int);
        void switch_cell(int, int);
        Swvec get_switched();
        int get_w();
        int get_h();

    protected:
        int count_next(int);


    private:
        int m_w;
        int m_h;
        float m_prop;
        int m_nbsw;
        std::string m_filename;
        std::vector<char> m_cells;
        std::vector<bool> m_switched;


};

#endif // MAP_HPP

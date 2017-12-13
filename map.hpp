#ifndef MAP_HPP
#define MAP_HPP
#include <string>
#include <vector>
#include <fstream>

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
        ~Map();
        void update();
        char get_cell(int, int);
        void set_cell(int, int, char);
        Swvec get_switched();
        int get_w();
        int get_h();

    protected:
        void load_map();
        int count_next(int);


    private:
        int m_w;
        int m_h;
        std::string m_filename;
        std::vector<char> m_cells;
        std::vector<bool> m_switched;


};

#endif // MAP_HPP

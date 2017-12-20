#ifndef CMD_HPP
#define CMD_HPP

#include <string>

#define OK 0
#define FAIL 1
#define HELP 2

class Cmd {
    public:
        Cmd(int, char**);
        ~Cmd();
        std::string get_filename();
        int get_csize();
        char p_state;
        bool create_new();
        int get_nw();
        int get_nh();
    private:
        std::string m_filename;
        bool m_new;
        int m_csize;
        int m_nw;
        int m_nh;
};

#endif // CMD_HPP

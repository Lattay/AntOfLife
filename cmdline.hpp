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
        int get_T();
        bool gol_enabled();
        bool ant_enabled();
        int get_csize();
        char p_state;
        bool use_random();
        int get_rw();
        int get_rh();
        float get_prop();
    private:
        std::string m_filename;
        int m_T;
        int m_random;
        bool m_gol;    
        bool m_ant;
        int m_csize;
        int m_rw;
        int m_rh;
        float m_prop;
};

#endif // CMD_HPP

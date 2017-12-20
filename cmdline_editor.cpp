#include <iostream>
#include "cmdline_editor.hpp"

int parseInt(char* s){
    int tot = 0;
    for(int i = 0; s[i] != 0; i++){
        if(s[i] >= 48 && s[i] < 58){
            tot = 10*tot + s[i] - 48;
        }
    }
    return tot;
}


Cmd::Cmd(int argc, char** argv):
    p_state(OK), m_filename("input.txt"), m_new(false), m_csize(-1), m_nw(80), m_nh(80)
{
    if(argc == 1){
        std::cout << "AntOfLifeEditor usage :" << std::endl;

        std::cout << "AntOfLifeEditor [-n W H][-s SIZE] FILENAME";
        std::cout << std::endl;

        std::cout << "Options :" << std::endl;

        std::cout << "-n W H\t\tcreate a new map of size WxH cells : ";
        std::cout << std::endl;

        std::cout << "-s SIZE\t\t\tset cell size in pixel.";
        std::cout << std::endl;

        std::cout << "FILENAME\t\tname of the file to use to save the map.";
        std::cout << " If the -n option is not used, the map is loaded from";
        std::cout << " this file.";
        std::cout << std::endl;
        p_state = HELP;
        return;
    } else {
        for(int i = 1; i < argc; i++){
            std::string s(argv[i]);
            if (s == "-n"){
                m_new = true;
                if(i < argc - 2){
                    m_nw = std::stoi(std::string(argv[++i]));
                    m_nh = std::stoi(std::string(argv[++i]));
                } else {
                    p_state = FAIL;
                    break;
                }
            } else if(s == "-s"){
                if(++i < argc){
                    m_csize = std::stoi(std::string(argv[++i]));
                } else {
                    p_state = FAIL;
                    break;
                }
            } else {
                m_filename = std::string(argv[i]);
            }
        }
    }
}

Cmd::~Cmd(){}

std::string Cmd::get_filename(){
    return m_filename;
}

int Cmd::get_csize(){
    return m_csize;
}

int Cmd::get_nw(){
    return m_nw;
}

int Cmd::get_nh(){
    return m_nh;
}

bool Cmd::create_new(){
    return m_new;
}

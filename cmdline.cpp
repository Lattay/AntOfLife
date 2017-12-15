#include <iostream>
#include "cmdline.hpp"

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
    p_state(OK), m_filename("input.txt"), m_T(200), m_random(false), m_gol(true), m_ant(true), m_csize(-1), m_rw(80), m_rh(80)
{
    if(argc == 1){
        std::cout << "AntOfLife usage :" << std::endl;

        std::cout << "AntOfLife [-r W H PROP][-t T]";
        std::cout << "[-m MODE][-s SIZE] [FILENAME]";
        std::cout << std::endl;

        std::cout << "Options :" << std::endl;

        std::cout << "-r W H PROP\t\tenter random mode : ";
        std::cout << "generate random map H cells high "; 
        std::cout << "and W cells large PROP%% cells alive.";
        std::cout << std::endl;

        std::cout << "-t T\t\t\teach generation last for T ";
        std::cout << "milliseconds. Default is 200.";
        std::cout << std::endl;

        std::cout << "-m MODE\t\t\tselect game mode : 'ant' ";
        std::cout << "for Langton's ant only, 'gol' for ";
        std::cout << "Conway's game of life only. Default ";
        std::cout << "is both at the same time." << std::endl;

        std::cout << "-s SIZE\t\t\tset cell size in pixel.";
        std::cout << std::endl;

        std::cout << "FILENAME\t\tif random mode is not ";
        std::cout << "enabled the map is loaded from a text ";
        std::cout << "file FILENAME where living cells are ";
        std::cout << "'*' and dead cells are anything else.";
        std::cout << std::endl;
        p_state = HELP;
        return;
    } else {
        for(int i = 1; i < argc; i++){
            std::string s(argv[i]);
            if (s == "-r"){
                m_random = true;
                if(i < argc - 3){
                    m_rw = std::stoi(std::string(argv[++i]));
                    m_rh = std::stoi(std::string(argv[++i]));
                    m_prop = std::stof(std::string(argv[++i]))/100.0;
                }
            } else if(s == "-t"){
                if(++i < argc){
                    m_T = std::stoi(std::string(argv[i]));
                } else {
                    p_state = FAIL;
                    break;
                }
            } else if(s == "-m"){
                if(++i < argc){
                    std::string mode(argv[i]);
                    if(mode == "ant"){
                        m_gol = false;
                        m_ant = true;
                    } else if(mode == "gol"){
                        m_gol = true;
                        m_ant = false;
                    } else {
                        m_gol = true;
                        m_ant = true;
                    }
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

int Cmd::get_T(){
    return m_T;
}

int Cmd::get_csize(){
    return m_csize;
}

bool Cmd::gol_enabled(){
    return m_gol;
}

bool Cmd::ant_enabled(){
    return m_ant;
}

bool Cmd::use_random(){
    return m_random;
}

int Cmd::get_rw(){
    return m_rw;
}

int Cmd::get_rh(){
    return m_rh;
}

float Cmd::get_prop(){
    return m_prop;
}

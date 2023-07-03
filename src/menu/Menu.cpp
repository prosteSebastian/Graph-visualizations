//
// Created by prokoseb on 3.7.23.
//

#include <iostream>
#include <limits>
#include "Menu.h"


void Menu::showOptions(std::ostream &out)const {
    out << _title << std::endl;
    for(size_t i = 0 ; i < _commands.size() ; ++i){
        out << "[" << i+1 << "] " << _commands[i] << std::endl;
    }
}

void Menu::runCommands(std::ostream &out) const {
    int choice = 0;
    while(std::cin && !choice && !_commands.empty()){
        out << "Enter your choice:" << std::endl;
        if(!(std::cin >> choice) || choice > static_cast<int>(_commands.size()) || choice <= 0){
            if(std::cin.bad()){
                throw std::runtime_error("Invalid input");
            }

            if(std::cin.eof()){
                throw std::runtime_error("EOF");
            }
            choice = 0;
            out << "Invalid choice" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<int>::max(), '\n');
        }
    }
    if(!choice){
        return;
    }
    _commands[choice - 1].action();
}

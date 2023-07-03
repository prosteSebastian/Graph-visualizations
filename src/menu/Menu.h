//
// Created by prokoseb on 3.7.23.
//

#ifndef MENU_H
#define MENU_H

#include <vector>
#include "MenuCommand.cpp"
class Menu {
public:
    Menu(std::string title) : _title(std::move(title)){}

    void showOptions(std::ostream &out)const;

    void runCommands(std::ostream &out)const;

private:
    std::string _title;
    std::vector<MenuCommand> _commands;
};


#endif //MENU_H

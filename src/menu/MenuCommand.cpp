#ifndef MENU_COMMAND_H
#define MENU_COMMAND_H
#include <ostream>
#include <string>
#include <functional>

class MenuCommand{
public:
    MenuCommand(std::string name, std::function<void()> action) : _name(std::move(name)), _action(std::move(action)){}

    void action()const {_action();}

    friend std::ostream &operator << (std::ostream &out,const MenuCommand &mC){
        return out << mC._name;
    }
private:
    std::string _name;
    std::function<void()> _action;
};

#endif //MENU_COMMAND_H

#include <iostream>
#include "menu/Menu.h"
int main() {
    Menu m("test");
    m.addCommand(MenuCommand("first command",[](){std::cout<<"HELL" << std::endl;}));
    try{
        while(std::cin){
            m.showOptions(std::cout);
            m.runCommands(std::cout);
        }
    }
    catch (std::exception &e){
        std::cout << e.what() << std::endl;
    }
  return 0;
}

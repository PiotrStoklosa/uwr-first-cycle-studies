#pragma once

#include <string>
#include <iostream>

namespace Functions
{

void print(std::vector<std::string> strings)
{
    for(auto& s : strings)
        std::cout << s <<" ";
    std::cout << std::endl;
}

static void quit()
{
    std::cout << "Console has quitted!" << std::endl;
    exit(0);
}

};

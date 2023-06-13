#pragma once

#include "Parser.hpp"
#include "Handlers.hpp"
#include <iostream>

class Console
{
public:
    void run()
    {
        std::string line;
        std::cout << "Welcome in terminal simulator.\nTry commands: \nprint [args...] \nquit" << std::endl;
        while (true)
        {
            std::cout << ">";
            getline(std::cin, line);
            const auto data = parser.parse(line);
            if (not handle(data))
                std::cout << "*** Unknown command! ***" << std::endl;
        }
    }

private:
    bool handle(const Parser::Data& data)
    {
        if (data.command == "quit")
            Functions::quit();
        else if (data.command == "print")
            Functions::print(data.parameters);
        else
            return false;
        return true;
    }

    Parser parser;
};

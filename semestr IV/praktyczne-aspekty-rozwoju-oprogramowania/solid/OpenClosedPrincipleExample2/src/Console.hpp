#pragma once

#include <vector>
#include <memory>
#include <iostream>

#include "Parser.hpp"
#include "CommandHandler.hpp"

class Console
{
public:
    void addHandler(std::unique_ptr<CommandHandler> handler)
    {
        handlers.push_back(std::move(handler));
    }

    void run()
    {
        std::string line;
        std::cout << "Welcome in terminal simulator.\nTry commands:\n";
        for (const auto& handler : handlers)
        {
            std::cout << handler->getCommandName() << "\n";
        }
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
        for (const auto& handler : handlers)
        {
            if (handler->getCommandName() == data.command)
            {
                handler->handle(data.parameters);
                return true;
            }
        }
        return false;
    }

    Parser parser;
    std::vector<std::unique_ptr<CommandHandler>> handlers;
};

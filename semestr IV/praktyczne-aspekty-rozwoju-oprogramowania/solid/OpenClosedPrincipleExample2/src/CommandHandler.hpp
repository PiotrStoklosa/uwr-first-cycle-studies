#pragma once

#include <vector>
#include <string>

class CommandHandler
{
public:
    virtual std::string getCommandName() const = 0;
    virtual void handle(const std::vector<std::string>& parameters) const = 0;
};

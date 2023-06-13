#pragma once

#include <vector>
#include <string>
#include <sstream>
#include <iterator>
#include <vector>

class Parser
{
public:
    struct Data
    {
        std::string command;
        std::vector<std::string> parameters;
    };

    Data parse(const std::string& line)
    {
        if (line.empty())
                return {};
        ss.clear();
        ss << line;
        return readData();
    }

private:
    Data readData()
    {
        Data result;
        ss >> result.command;
        result.parameters = readParameters();
        return result;
    }

    std::vector<std::string> readParameters()
    {
        return std::vector<std::string>(std::istream_iterator<std::string>(ss), std::istream_iterator<std::string>());
    }

    std::stringstream ss;
};

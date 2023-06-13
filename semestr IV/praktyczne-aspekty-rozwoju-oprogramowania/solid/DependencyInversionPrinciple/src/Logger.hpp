#pragma once
#include <string>
#include <memory>
#include "SqlDataSaver.hpp"


class Logger
{
public:
    Logger(SqlAdress adress)
    {
        dataSaver.reset(new SqlDataSaver(adress));
    }

    void log(std::string log)
    {
        dataSaver->saveData(log);
    }

private:
    std::unique_ptr<SqlDataSaver> dataSaver;
};




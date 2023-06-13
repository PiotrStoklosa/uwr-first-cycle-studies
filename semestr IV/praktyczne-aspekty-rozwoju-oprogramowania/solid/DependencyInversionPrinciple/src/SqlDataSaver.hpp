#pragma once
#include <string>
#include <iostream>

class SqlAdress
{
public:
    SqlAdress(std::string adress)
        :sqlAdress(adress)  {}

    std::string get()  {return sqlAdress;}
private:
    std::string sqlAdress;
};


class SqlDataSaver
{
public:
    SqlDataSaver(SqlAdress adress)
    {
        std::cout << "SQL data Saver created. Connection established at: " << adress.get() << std::endl;
    }

    void saveData(std::string data)
    {
        std::cout << "saving data to sql db: " << data << std::endl;
    }
};


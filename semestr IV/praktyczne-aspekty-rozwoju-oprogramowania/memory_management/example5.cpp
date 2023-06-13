#include <iostream>
#include <chrono>

struct Partner {};

std::size_t getCurrentTime()
{
    return std::chrono::system_clock::now().time_since_epoch().count();
}

bool process()
{
    if (getCurrentTime() % 17 == 0) throw 17;
    return true;
}

bool processSecond()
{
	if (getCurrentTime() % 2) throw 3.14;
	return true;
}

void convertMe()
{
    Partner* pFirst = new Partner();

    if (!process())
    {
        delete pFirst;
        return;
    }

    Partner* pSecond = new Partner();

    if (!processSecond())
    {
        delete pFirst;
        delete pSecond;
        return;
    }

    process();
    delete pFirst;
    delete pSecond;
}

int main()
{
    try
    {
        convertMe();
    }
    catch(int i)
    {
        std::cout << "Ups: " << i << std::endl;
    }
    catch(double d)
    {
        std::cout << "Ups: " << d << std::endl;
    }
    return 0;
}

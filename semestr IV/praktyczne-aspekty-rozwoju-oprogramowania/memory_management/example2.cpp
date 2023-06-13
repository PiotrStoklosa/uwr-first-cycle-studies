#include <iostream>
#include <vector>

std::vector<int*> allocateInts()
{
    std::vector<int*> numbers;
    for(int i = 0; i < 10; i++)
    {
        numbers.push_back(new int(i));
        std::cout << "Added " << i << std::endl;
    }
    return numbers;
}

void deallocateInts(std::vector<int*> numbers)
{
    for(auto number : numbers)
    {
        delete number;
    }
}

int main()
{
    std::vector<int*> num = allocateInts();
    std::cout << "Hello World!" << std::endl;
    return 0;
}


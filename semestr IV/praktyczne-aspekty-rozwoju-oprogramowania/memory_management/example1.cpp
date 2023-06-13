#include <iostream>

int main()
{
    int* num = new int(10);
    std::cout << "Hello World!" << std::endl
              << "Created new int: " << *num << std::endl;
    return 0;
}


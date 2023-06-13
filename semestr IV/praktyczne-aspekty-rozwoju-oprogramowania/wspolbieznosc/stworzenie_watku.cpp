#include <iostream>
#include <chrono>
#include <thread>
#include <string>

void greeter(std::string who)
{
  for (size_t i = 0; i < 5; i++)
  {
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    std::cout << "Hi " << who << "!" << std::endl;
  }
}

int main()
{
  std::string name("Piotr");

  // TODO: stworzyc watek

  std::thread greet(&greeter, name);



  std::this_thread::sleep_for(std::chrono::seconds(5));
    greet.join();

  return 0;
}

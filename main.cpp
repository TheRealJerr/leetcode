#include <iostream>
#include "thread.hpp"


auto main() -> int
{
    Thread([](){ std::cout << "hello world" << std::endl; }).join();
    return 0;
}
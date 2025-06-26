#include <iostream>
#include "thread.hpp"


auto main() -> int
{
    Thread([](int left, int right){ std::cout << "hello world" << std::endl; }, 1, 2 ).join();
    return 0;
}
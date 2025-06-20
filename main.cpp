#include <iostream>
#include <thread>
#include <future>
int plus(int left,int right) 
{
    return left + right;
}
auto main() -> int
{
    std::promise<int> prom;
    std::future<int> f = prom.get_future();
    std::thread([&_prom = prom](int left,int right) mutable {
        auto t = plus(left,right);
        _prom.set_value(t);
    }, 1, 2).join();

    std::this_thread::sleep_for(std::chrono::seconds(1));

    std::cout << f.get() << std::endl;
    return 0;
}
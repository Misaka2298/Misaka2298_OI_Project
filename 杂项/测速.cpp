#include <iostream>
#include <chrono>
#include <windows.h>

int main()
{
    using namespace std::chrono;
    const auto limit = milliseconds(1000);   // 1 s
    volatile long long counter = 0;          // volatile 防止优化掉
    auto t0 = steady_clock::now();

    while (steady_clock::now() - t0 < limit)
        ++counter;

    std::cout << counter;
    std::cout << std::endl << counter / 1000.0;
    system("pause");
    return 0;
}
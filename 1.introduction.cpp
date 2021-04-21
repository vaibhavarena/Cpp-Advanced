#include <iostream>

template <typename T>
T maxOf(const T &a, const T &b)
{
    return ( a > b ? a : b);
}

int main()
{
    std::cout << maxOf<int>(34,9) << "\n";
    std::cout << maxOf<char>('a', 'z') << "\n";
}
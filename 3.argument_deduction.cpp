#include <iostream>
#include <string>
#include <vector>

template <typename T>
void printv(const std::vector<T> &v)
{
    if(v.empty()) return;

    for(const T &i : v)
        std::cout << i << " ";
    
    std::cout << "\n";
}

int main()
{
    std::vector<int> i = {1, 2, 3, 4, 5};
    std::vector<std::string> s = {"one", "two", "three", "four", "five"};

    printv(i);
    printv(s);
}
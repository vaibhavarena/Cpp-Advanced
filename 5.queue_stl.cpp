#include <iostream>
#include <queue>
#include <list>
#include <deque>

template <typename T>
void reportQ(T &q)
{
    size_t s = q.size();
    std::cout << "Size : " << s;

    if(s)
        std::cout << "  Front : " << q.front() << "  Back : " << q.back() << "\n";
}

template <typename T>
void popAll(T &q)
{
    while(!q.empty())
    {
        std::cout << q.front() << " ";
        q.pop();
    }
    std::cout << "\n";
}

int main()
{
    std::list<int> l1 = {1, 2, 3, 4};

    std::queue<int, std::list<int>> q1(l1);     // Not specifying the container,
                                                // will automatically choose deque
    reportQ(q1);
    popAll(q1);
}
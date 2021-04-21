#include <iostream>
#include <map>
#include <utility>
#include <string>

using namespace std;

template <typename T>
void printM(const T &m)
{
    for(const pair<string, string> &p : m)
        cout << p.first << " " << p.second << "\n";
}

int main()
{
    map<string, string> m = {{"A", "B"}, {"C", "D"}};

    printM(m);
}
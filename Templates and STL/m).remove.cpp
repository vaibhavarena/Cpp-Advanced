#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>

using namespace std;

template <typename T>
void dispV(const vector<T> & v)
{
    if(v.empty()) return;

    for(const T &i : v)
        cout << i << " ";
    cout << endl;
}

int main()
{
    vector<int> v = {1,2,3,4,5};

    cout << v.size() << endl;

    vector<int>::iterator i = remove(v.begin(), v.end(), 3);

    v.resize(i - v.begin());     // Use after remove to resize the container

    cout << v.size() << endl;
}
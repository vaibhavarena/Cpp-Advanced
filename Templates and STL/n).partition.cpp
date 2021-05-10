#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

template <typename T>
bool is_even(const T & v)
{
    return (v % 2 == 0);
}

template <typename T>
void dispVect(const vector<T> & v)
{
    if(v.empty()) return;

    for(const T & i : v)
        cout << i << " ";
    cout << endl;
}

int main()
{
    vector<int> v1 = { 11, 13, 18, 19, 23, 29, 31, 37, 41, 42, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 98 };

    auto r = is_even<int>;

    partition(v1.begin(), v1.end(), r);
    dispVect(v1);
}

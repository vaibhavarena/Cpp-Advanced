#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
void dispVect(const vector<T> & v){
    if(v.empty()) return;

    for(bool i : v)
        cout << ( i ? "T" : "F" ) << " ";
    cout << endl;
}

int main()
{
    vector<long> v1 = {2,6,19,29,4};
    vector<long> v2 = {1,9, 12, 48, 8};
    vector<bool> v3(v2.size());

    greater<long> g;

    transform(v1.begin(), v1.end(), v2.begin(), v3.begin(), g);

    dispVect(v3);
}
#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
void dispVect(const vector<T> & v){
    if(v.empty()) return;

    for(const T & i : v)
        cout << i << " ";
    cout << endl;
}

int main()
{
    vector<long> v1 = {1,2,3,4,5};
    vector<long> v2 = {6,7,8,9,10};
    vector<long> v3(v2.size());

    plus<long> f;

    transform(v1.begin(), v1.end(), v2.begin(), v3.begin(), f);
    dispVect(v3);
}
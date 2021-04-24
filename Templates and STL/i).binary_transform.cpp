#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
class accum{
    T _accum = 1;

    public:
        T operator() (const T &n1, const T &n2){
            return _accum = _accum * n1 * n2;
        }
};

template <typename T>
void dispV(const vector<T> &v)
{
    if(v.empty()) return;

    for(const &i : v)
        cout << i << " ";
    
    cout << endl;
}


int main()
{
    accum<int> a;
    vector<int> v1 = {1,2,3,4,5};
    vector<int> v2 = {6,7,8,9,10};
    vector<int> v3(v1.size());

    transform(v1.begin(), v1.end(), v2.begin(), v3.begin(), a);
    dispV(v3);

    int acc = 10;
    transform(v1.begin(), v1.end(), v2.begin(), v3.begin(), [acc](int &a, int &b){
        return acc * a * b;
    });

    dispV(v3);   
}
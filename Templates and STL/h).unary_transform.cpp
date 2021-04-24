#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

template <typename T>
class accum{
    private:
        int _acc = 0;
        accum(){}

    public:
        accum(T n) : _acc(n){}
        T operator()(T y){ 
            _acc += y; 
            return _acc;
        }
};

template <typename T>
void dispVect(vector<T> &y)
{
    if(y.empty()) return;

    for(const T &i : y)
        cout << i << " ";

    cout << endl;
}

int main()
{
    accum<int> x(7);

    // Without using accum class
    int acc = 7;
    auto y = [acc](int d) mutable -> int { return acc += d; };

    cout << x(7) << endl;

    vector<int> v = {2,3,4,5};
    vector<int> v1(v.size());

    transform(v.begin(), v.end(), v1.begin(), x);
    dispVect(v1);
    transform(v.begin(), v.end(), v1.begin(), y);
    dispVect(v1);


    vector<string> s = {"One", "Two", "Three", "Four", "Five"};
    vector<size_t> s1(s.size());

    transform(s.begin(), s.end(), s1.begin(), [](string &y) -> size_t {return y.size();});
    dispVect(s1);
}
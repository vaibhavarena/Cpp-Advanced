#include <iostream>

using namespace std;

template <typename T>
class multi{
    T num = 0;
    multi();

    public:
        multi(T n) : num(n){}

        void mult(T n){num = n;}
        const T m(){return num;}

        T operator()(const T &a){
            return a * num;
        }
};

int main()
{
    multi<int> x(23);
    cout << x.m() << endl;
    cout << x(10) << endl;
    
    x.mult(10);
    cout << x.m() << endl;
    cout << x(10) << endl;
}
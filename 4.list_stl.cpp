#include <list>
#include <iostream>

using namespace std;

template <typename T>
void printL(const list<T> &l){
    if(l.empty()) return;

    for(const T &i : l)
        cout << i << " ";

    cout << endl;
}

int main()
{
    list<int> l1 = {1, 2, 3, 4, 5};

    printL(l1);

    // Insertion
    list<int>::iterator it1 = l1.begin();

    while((*++it1 != 5) && (it1 != l1.end()));

    if(it1 != l1.end())
        l1.insert(it1, 112);

    printL(l1);

    // Erase
    it1 = l1.begin();

    while((*++it1 != 112) && (it1 != l1.end()));

    l1.erase(it1);
    // l1.erase(it1, it2)  Erase a range    Inclusive it1, Exclusive it2

    printL(l1);
}
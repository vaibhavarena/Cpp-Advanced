#include <iostream>
#include <iterator>
#include <forward_list>     // Single linked list type
#include <set>
#include <vector>

using namespace std;

int main()
{
    double d1 = 0, d2 = 0;

    cout << "Two numeric values : ";
    cin.clear();

    // Input iterator
    istream_iterator<double> eos;
    istream_iterator<double> iit(cin);

    if(iit == eos){
        cout << "No values given\n";
        return 0;
    }
    else{
        d1 = *iit++;
    }

    if(iit == eos){
        cout << "No second value\n";
        return 0;
    }
    else{
        d2 = *iit;
    }

    cin.clear();
    cout << d1 << " * " << d2 << " = " << d1 * d2 << endl;


    // Output iterator
    ostream_iterator<int> output(cout, " ");

    for(int i : {3,4,5}){
        *output++ = i;
    }


    // Forward iterator
    forward_list<int> fl1 = {1,2,3};
    forward_list<int>::iterator ftr;

    for(ftr = fl1.begin(); ftr != fl1.end(); ++ftr)
    {
        cout << *ftr <<" ";
    }
    cout << endl;


    // Bi directional iterator
    set<int> s = {11,12,13,14,15};
    set<int>::iterator btr;

    // end() returns an iterator past the end
    for(btr = s.begin(); btr != s.end(); ++btr)
    {
        cout << *btr << " ";
    }
    cout << endl;

    for(btr = s.end(); btr != s.begin(); )
    {
        cout << *--btr << " ";
    }
    cout << endl;


    // Random iterator
    // Additional functionality in addition to above functionality

    vector<int> v = {21, 22, 23, 24, 25};
    vector<int>::iterator vtr;

    cout << * v.begin() + 2 << "\n";
    cout << v[4] << "\n";

}
// C++ program to illustrate set
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main()
{
    // creating vector
    vector<int> v = { 1,1,1,1, 5, 3, 4, 2 }; //donot store multiple occurance in set
    // creating set using vector v
    set<int> s(v.begin(), v.end());

    // finding 4
    if (s.find(4) == s.end()) {
        cout << "4 not found" << endl;
    }
    else {
        cout << "4 found" << endl;
    }
    auto it=s.find(4);
    s.erase(it);

    // adding 9
    s.insert(9);

    // printing set
    cout << "s: ";
    for (set<int>::iterator i = s.begin(); i != s.end(); i++) {
        cout << *i << " ";
    }
    cout << endl;
    return 0;
}
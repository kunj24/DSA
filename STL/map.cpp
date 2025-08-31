// C++ Program to illustrate the map container
#include <iostream>
#include <map>
using namespace std;

int main()
{
    // creating std::map object
    map<int, string> m;                                            // store in the sorted oreder of key
    map<int, pair<int, int>> x;

    // Adding elements to map x
    x[1] = {11, 33};
    x[3] = {122, 233};
    x[2] = {132, 3453};

    // adding elements to map m
    m[1] = "ONE";
    m[2] = "TWO";
    m[3] = "THREE";

    // checking size
    cout << "Size of map m: " << m.size() << endl;
    cout << "Size of map x: " << x.size() << endl;
    // inserting using insert pair
    m.insert({4, "FOUR"});

    // deleting key 2 with its value
    m.erase(2);

    // printing the map m
    cout << "Map m:-" << endl;
    for (auto i : m) {
        cout << "Key: " << i.first << '\t';
        cout << "Value: " << i.second << endl;
    }

    // printing the map x with proper pair formatting
    cout << "Map x:-" << endl;
    for (auto i : x) {
        cout << "Key: " << i.first << '\t';
        cout << "Value: (" << i.second.first << ", " << i.second.second << ")" << endl;
    }

    return 0;
}
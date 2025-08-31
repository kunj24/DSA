// C++ program to illustrate the deque
#include <deque>
#include <iostream>
using namespace std;

int main()
{
    // creating a deque
    deque<int> d = { 1, 2, 3, 4, 5 };

    // removing two elements from the back and pushing them
    // at the front
    d.push_front(d.back());
    d.pop_back();
    d.push_front(d.back());
    d.pop_back();

    for (auto i : d) {
        cout << i << " ";
    }

    return 0;
}
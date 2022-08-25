#include <set>
#include<algorithm>
#include <iostream>

using namespace std;

int main()
{
    set<int> s;
    s = {1, 2, 2, 3, 4, 4, 4, 5, 6, 7, 8, 8, 8, 8, 9, 10};
    cout << s.size() << endl;
    cout << s.max_size() << endl;
    cout <<"MAX: "<<*max_element(s.begin(), s.end()) << endl;
    cout <<"MIN: "<<*min_element(s.begin(), s.end()) << endl;
    s.insert(11);
    cout << "s: ";
    for (auto i : s)
        cout << i << " ";
    cout << endl;

    //*******************************************
   
}
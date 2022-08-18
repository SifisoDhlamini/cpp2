#include <iostream>
#include <tuple>

using namespace std;

int main()
{
    //create an array of tuples(string, int)
    tuple<string, int> arr[] = {
        make_tuple("one", 1),
        make_tuple("two", 2),
        make_tuple("three", 3),
        make_tuple("four", 4),
        make_tuple("four", 4),
        make_tuple("five", 5),
        make_tuple("six", 6),
        make_tuple("seven", 7),
        make_tuple("eight", 8),
        make_tuple("nine", 9),
        make_tuple("ten", 10)};

    //print the array
    for (auto i : arr)
        cout << get<0>(i) << " " << get<1>(i) << endl;

    //*******************************************
    tuple<int, char> foo(10, 'x');
    auto bar = make_tuple("test", 3.1, 14, 'y');

    get<2>(bar) = 100; // access element

    int myint;
    char mychar;

    tie(myint, mychar) = foo;                 // unpack elements
    tie(ignore, ignore, myint, mychar) = bar; // unpack (with ignore)

    mychar = get<3>(bar);

    get<0>(foo) = get<2>(bar);
    get<1>(foo) = mychar;

    cout << "foo contains: ";
    cout << get<0>(foo) << ' ';
    cout << get<1>(foo) << '\n';
}
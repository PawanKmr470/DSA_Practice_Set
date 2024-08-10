#include <iostream>
#include <vector>
using namespace std;

// [capture list] (arguments) { funtion body}
// capture list
// arguments
// return type
// body of function
// Acronym : CARB

int main() {

    vector<int> v1 = {20,4,3,5};

    for_each(v1.begin(), v1.end(), [](int x){ cout << x << " ";} );
    cout << endl;

    auto display = [](int x){ cout << x << " ";};
    for_each(v1.begin(), v1.end(), display);
    cout << endl;

    // [&variable_name] would be accessible inside lambda function definition & mutable.
    // [variable_name] would do the same but immutable.
    // To make all variales accessible and mutable in this scope use :  [&]
    // To make all variales accessible and immutable in this scope use :  [=]
    int sum = 0;
    for_each(v1.begin(), v1.end(), [&](int x){ sum += x;} );
    cout << sum << endl;

    // Two arguments in lambda
    sort(v1.begin(), v1.end(), [] (int a, int b) { return a < b;});
    for (auto &i : v1)
        cout << i << " ";
    cout << endl;

    // In above lambda function is returning boolean (true/false)
    // Syntactically we can explicityly define it
    sort(v1.begin(), v1.end(), [] (int a, int b) -> bool { return a > b;});
    for (auto &i : v1)
        cout << i << " ";
    cout << endl;
    
}
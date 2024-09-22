#include <iostream>
#include <string>
using namespace std;

// NOTES :
//      First way  : is to reverse it and compare with original string
//      Second way : Start from begining and end & compare towards middle (Iterative & Recursion)
//      Third way  : is go to the middle and expand outwards [need to consider even odd cases] (expand from center)

// Second way
bool Palindrome1(string s) {
    int i = 0;
    int j = s.size() - 1;

    while (i <= j) {
        if (s[i] == s[j]) {
            i++;
            j--;
        }
        else
            return false;
    }

    return true;
}

bool helper(string& s, int i, int j) {
    if (i >= j)
        return true;    // Base condition : if indices have reached here means string was palindrome
    
    if (s[i] == s[j])
        return helper(s, i + 1, j - 1);
    else
        return false;
}

bool Palindrome2(string s) {
    int i = 0;
    int j = s.size() - 1;

    return helper(s, i, j);
}


int main() {
    string s = "tenet";
    cout << Palindrome1(s) << endl;
    cout << Palindrome2(s) << endl;
    return 0;
}
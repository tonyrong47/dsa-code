#include <iostream>
#include <algorithm>
using namespace std;

void checkPal(string s) {
    string r = s;
    reverse(r.begin(), r.end());
    if (s == r) 
        cout << "\"" << s << "\" is palindrome.\n";
    else 
        cout << "\"" << s << "\" is NOT palindrome.\n";
}

int main() {
    checkPal("ABCDCBA");
    checkPal("ABCD");
    return 0;
}

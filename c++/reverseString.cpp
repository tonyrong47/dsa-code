#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int st = 0;
        int e = s.size() - 1;
        while(st < e) {
            swap(s[st++], s[e--]);
        }
    }
};

int main() {
    // Example input string as vector<char>
    vector<char> s = {'h', 'e', 'l', 'l', 'o'};

    Solution sol;
    sol.reverseString(s);

    // Printing the reversed string
    for(char c : s) {
        cout << c;
    }
    cout << endl;

    return 0;
}
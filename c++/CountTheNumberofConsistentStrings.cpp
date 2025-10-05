#include <iostream>
#include <unordered_set>
using namespace std;
// Brute force solution
int countConsistentStringsBrute(string allowed, vector<string> &words)
{
    int cnt = 0;
    unordered_set<char> aset(allowed.begin(), allowed.end());

    for (int i = 0; i < words.size(); i++)
    {
        bool wordFound = true;
        for (int j = 0; j < words[i].size(); j++)
        {

            if (aset.find(words[i][j]) == aset.end())
            {
                wordFound = false;
                break;
            }
        }
        if (wordFound)
        {
            cnt++;
        }
    }
    return cnt;
}

// Optimal solution
int countConsistentStringsOptimal(string allowed, vector<string> &words)
{
    int cnt = 0;
    int mask = 0;

    // Create bitmask for allowed characters
    for (char ch : allowed)
    {
        mask |= (1 << (ch - 'a'));
    }

    for (const string &word : words)
    {
        bool isConsistent = true;
        for (char ch : word)
        {
            if ((mask & (1 << (ch - 'a'))) == 0)
            {
                isConsistent = false;
                break;
            }
        }
        if (isConsistent)
            cnt++;
    }

    return cnt;
}

int main()
{
    string allowed = "ab";
    vector<string> words = {"ad", "bd", "aaab", "baa", "badab"};
    cout << "Count the Number of Consistent Strings : " << countConsistentStringsBrute(allowed, words) << endl;
    cout << "Count the Number of Consistent Strings : " << countConsistentStringsOptimal(allowed, words) << endl;

    return 0;
}
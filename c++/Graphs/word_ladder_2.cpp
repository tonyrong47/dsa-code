#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f(i, a, b) for (int i = a; i < b; i++)
#define all(x) x.begin(), x.end()
#define vprint(v)            \
    for (auto &elem : v)     \
        cout << elem << " "; \
    cout << endl;
#define mprint(m)                                       \
    for (auto it : m)                                   \
        cout << it.first << " : " << it.second << endl; \
    cout << endl;
#define vint vector<int>
#define vstring vector<string>
#define vmat vector<vector<int>>
#define FAST_IO                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define mii map<int, int>
#define mll map<ll, ll>

const int INF = 1e9;
const ll MOD = 1e9 + 7;

unordered_map<string, int> mpp;
vector<vector<string>> ans;
string b;
void dfs(string word, vector<string> &seq)
{
    if (word == b)
    {
        reverse(seq.begin(), seq.end());
        ans.push_back(seq);
        reverse(seq.begin(), seq.end());
        return;
    }
    int steps = mpp[word];
    int sz = word.size();
    for (int i = 0; i < sz; i++)
    {
        char original = word[i];
        for (char ch = 'a'; ch <= 'z'; ch++)
        {
            word[i] = ch;
            if (mpp.find(word) != mpp.end() && mpp[word] + 1 == steps)
            {
                seq.push_back(word);
                dfs(word, seq);
                seq.pop_back();
            }
        }
        word[i] = original;
    }
}

vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
{
    unordered_set<string> st(wordList.begin(), wordList.end());
    queue<string> q;
    b = beginWord;
    q.push(beginWord);
    mpp[beginWord] = 1;
    int sz = beginWord.size();
    st.erase(beginWord);
    while (!q.empty())
    {
        string word = q.front();
        int steps = mpp[word];
        q.pop();
        if (word == endWord)
            break;
        for (int i = 0; i < sz; i++)
        {
            char original = word[i];
            for (char ch = 'a'; ch <= 'z'; ch++)
            {
                word[i] = ch;
                if (st.count(word))
                {
                    q.push(word);
                    mpp[word] = steps + 1;
                }
            }
            word[i] = original;
        }
    }
    if (mpp.find(endWord) != mpp.end())
    {
        vector<string> seq;
        seq.push_back(endWord);
        dfs(endWord, seq);
    }
    return ans;
}

int main()
{
    FAST_IO;

    return 0;
}
// by ad73prem
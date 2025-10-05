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

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
{
    int n = image.size();
    int m = image[0].size();

    queue<pair<int, int>> q;
    vector<vector<int>> vis(n, vector<int>(m, 0));

    q.push({sr, sc});
    int clr = image[sr][sc];
    image[sr][sc] = color;
    vis[sr][sc] = color;

    vector<int> drow = {-1, 0, 1, 0};
    vector<int> dcol = {0, 1, 0, -1};

    while (!q.empty())
    {
        auto node = q.front();
        int r = node.first;
        int c = node.second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nrow = r + drow[i];
            int ncol = c + dcol[i];
            if (nrow >= 0 && nrow < n && ncol < m && ncol >= 0 && vis[nrow][ncol] != color && image[nrow][ncol] == clr)
            {
                q.push({nrow, ncol});
                image[nrow][ncol] = color;
                vis[nrow][ncol] = color;
            }
        }
        // cout<<"r : "<<r<<" c : "<<c<<endl;
        // for(int i=0;i<image.size();i++){
        //     vprint(image[i]);
        // }
    }
    return image;
}

int main()
{
    FAST_IO;
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    vmat image = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
    vmat ans = floodFill(image, 1, 1, 2);
    for (int i = 0; i < ans.size(); i++)
    {
        vprint(ans[i]);
    }
    return 0;
}
// by ad73prem
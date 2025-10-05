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

int orangesRotting(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();

    queue<pair<pair<int, int>, int>> q;
    vector<vector<int>> vis(n, vector<int>(m, 0));
    // cout<<"hello";
    // declaring starting nodes
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 2)
            {
                q.push({{i, j}, 0});
                // mark them rotten in the visited array as well
                vis[i][j] = 2;
            }
            else
            {
                vis[i][j] = 0;
            }
        }
    }

    int tm = 0;
    vector<int> drow = {-1, 0, 1, 0};
    vector<int> dcol = {0, 1, 0, -1};
    while (!q.empty())
    {
        auto node = q.front();
        int r = node.first.first;
        int c = node.first.second;
        int t = node.second;
        tm = max(tm, t);
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nrow = r + drow[i];
            int ncol = c + dcol[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] != 2 && grid[nrow][ncol] == 1)
            {
                q.push({{nrow, ncol}, t + 1});
                vis[nrow][ncol] = 2;
            }
        }
        // for(int i=0;i<vis.size();i++){
        //     vprint(vis[i]);
        // }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (vis[i][j] != 2 && grid[i][j] == 1)
            {
                return -1;
            }
        }
    }
    return tm;
}

int main()
{
    FAST_IO;
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // cout<<"hello";
    vmat grid = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
    cout << orangesRotting(grid);
    return 0;
}
// by ad73prem
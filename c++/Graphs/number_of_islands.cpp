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

void bfs(int r, int c, vector<vector<int>> &grid, vector<vector<int>> &vis)
{
    int n = grid.size();     // number of rows
    int m = grid[0].size();  // number of columns
    vis[r][c] = 1;           // mark as visited
    queue<pair<int, int>> q; // queue required for bfs
    vector<int> drow = {-1, -1, -1, 0, 0, 1, 1, 1};
    vector<int> dcol = {-1, 0, 1, -1, 1, -1, 0, 1};
    q.push({r, c});
    while (!q.empty())
    {
        auto node = q.front();
        q.pop();
        int r = node.first;
        int c = node.second;
        for (int i = 0; i < 8; i++)
        {
            int nrow = r + drow[i];
            int ncol = c + dcol[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] != 1 && grid[nrow][ncol] == 1)
            {
                q.push({nrow, ncol});
                vis[nrow][ncol] = 1;
            }
        }
    }
}

int numberOfIslands(vector<vector<int>> &grid)
{
    int n = grid.size();                           // number of rows
    int m = grid[0].size();                        // number of columns
    vector<vector<int>> vis(n, vector<int>(m, 0)); // visited array

    int cnt = 0; // for counting

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j] && grid[i][j] == 1)
            {
                cnt++;
                bfs(i, j, grid, vis);
            }
        }
    }
    return cnt;
}

int main()
{
    FAST_IO;

    return 0;
}
// by ad73prem
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

bool detectCycle(vector<vector<int>> &adj)
{
    int n = adj.size();
    // make the indegree array
    vector<int> indegree(n, 0);
    for (int i = 0; i < n; i++)
    {
        for (auto it : adj[i])
        {
            indegree[it]++;
        }
    }

    // start the bfs from the node with indegree 0
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    // start the bfs and the topological sorting
    vector<int> topo;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        topo.push_back(node);
        for (auto it : adj[node])
        {
            indegree[it]--;
            if (indegree[it] == 0)
            {
                q.push(it);
            }
        }
    }
    if (topo.size() < n)
    {
        return true;
    }
    return false;
}

bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
{
    vector<vector<int>> adj(numCourses);
    for (auto it : prerequisites)
    {
        adj[it[1]].push_back(it[0]);
    }
    // for(int i=0;i<numCourses;i++){
    //     vprint(adj[i]);
    // }
    // the courses must not be cyclic in order to be completed, means there shouldnt be any cycle in hte entire graph of the directed course
    if (detectCycle(adj) == true)
        return false;
    return true;
}

int main()
{
    FAST_IO;
    vector<vector<int>> mat = {{1, 0}};
    cout << canFinish(2, mat);
    return 0;
}
// by ad73prem
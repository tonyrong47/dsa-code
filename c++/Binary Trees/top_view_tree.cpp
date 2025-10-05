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

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<int> topView(TreeNode *root)
{
    map<int, map<int, multiset<int>>> nodes;
    queue<pair<TreeNode *, pair<int, int>>> todo;
    todo.push({root, {0, 0}});
    while (!todo.empty())
    {
        auto p = todo.front();
        todo.pop();
        TreeNode *node = p.first;
        int x = p.second.first;
        int y = p.second.second;
        nodes[x][y].insert(node->val);
        if (node->left)
        {
            todo.push({node->left, {x - 1, y + 1}});
        }
        if (node->right)
        {
            todo.push({node->right, {x + 1, y + 1}});
        }
    }
    vector<int> ans;
    for (auto p : nodes)
    {
        auto it = p.second.begin();
        int firstVal = *it->second.begin();
        ans.push_back(firstVal);
    }

    return ans;
}

vector<int> bottomView(TreeNode *root)
{
    map<int, map<int, multiset<int>>> nodes;
    queue<pair<TreeNode *, pair<int, int>>> todo;
    todo.push({root, {0, 0}});
    while (!todo.empty())
    {
        auto p = todo.front();
        todo.pop();
        TreeNode *node = p.first;
        int x = p.second.first;
        int y = p.second.second;
        nodes[x][y].insert(node->val);
        if (node->left)
        {
            todo.push({node->left, {x - 1, y + 1}});
        }
        if (node->right)
        {
            todo.push({node->right, {x + 1, y + 1}});
        }
    }
    vector<int> ans;
    for (auto p : nodes)
    {
        auto it = prev(p.second.end());
        int firstVal = *prev(it->second.end());
        ans.push_back(firstVal);
    }

    return ans;
}

int main()
{
    FAST_IO;
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(3);
    root->left->left->right = new TreeNode(4);
    root->left->left->right->left = new TreeNode(5);
    root->left->left->right->right = new TreeNode(6);
    root->right->right = new TreeNode(8);
    root->right->right->left = new TreeNode(9);
    root->right->right->left->left = new TreeNode(10);
    root->right->right->left->right = new TreeNode(11);

    vint ans = bottomView(root);
    vprint(ans);
    return 0;
}
// by ad73prem
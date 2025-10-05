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

vector<vector<int>> lvlOrder(TreeNode *root)
{
    if (!root)
        return {};
    vector<vector<int>> ans;
    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        int size = q.size();
        vector<int> lvl;
        for (int i = 0; i < size; i++)
        {
            TreeNode *node = q.front();
            q.pop();
            lvl.push_back(node->val);

            if (node->left)
            {
                q.push(node->left);
            }
            if (node->right)
            {
                q.push(node->right);
            }
        }
        ans.push_back(lvl);
    }
    return ans;
}

bool isSymmetric(TreeNode *root)
{
    vector<vector<int>> a = lvlOrder(root->left);
    vector<vector<int>> b = lvlOrder(root->right);
    if (a.size() != b.size())
        return false;
    for (int i = 0; i < a.size(); i++)
    {
        reverse(b[i].begin(), b[i].end());
        if (a[i] != b[i])
            return false;
    }
    return true;
}

int main()
{
    FAST_IO;
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(2);
    cout << isSymmetric(root);
    return 0;
}
// by ad73prem
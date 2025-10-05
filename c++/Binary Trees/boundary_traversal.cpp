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

int left(TreeNode *root)
{
}

// gets the left boundary wihtout the leaf nodes
void getLeftBoundary(TreeNode *node, vector<int> &ans)
{
    while (node)
    {
        if (node->left || node->right)
        {
            ans.push_back(node->val);
        }
        if (node->left)
        {
            node = node->left;
        }
        else
        {
            node = node->right;
        }
    }
}

void getRightBoundary(TreeNode *node, vector<int> &ans)
{
    while (node)
    {
        if (node->left || node->right)
        {
            ans.push_back(node->val);
        }
        if (node->right)
        {
            node = node->right;
        }
        else
        {
            node = node->left;
        }
    }
}

void getLeafNodes(TreeNode *node, vector<int> &ans)
{
    if (node == NULL)
        return;
    if (node->left == NULL && node->right == NULL)
    {
        ans.push_back(node->val);
        return;
    }
    getLeafNodes(node->left, ans);
    getLeafNodes(node->right, ans);
}

vector<int> boundaryTraversal(TreeNode *root)
{
    vector<int> ans;
    TreeNode *node = root;
    getLeftBoundary(node, ans);
    vprint(ans);
    vector<int> ans2;
    getRightBoundary(node, ans2);
    vprint(ans2);
    vector<int> ans3;
    getLeafNodes(node, ans3);
    vprint(ans3);
    vector<int> final;
    final.insert(final.end(), ans.begin(), ans.end());
    final.insert(final.end(), ans3.begin(), ans3.end());
    reverse(ans2.begin(), ans2.end());
    final.insert(final.end(), ans2.begin(), ans2.end() - 1);
    vprint(final);
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
    vint ans = boundaryTraversal(root);
    vprint(ans);
    return 0;
}
// by ad73prem
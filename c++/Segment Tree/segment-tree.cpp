#include <bits/stdc++.h>
using namespace std;
class SGTree
{
private:
    vector<long long> seg;
 
public:
    SGTree(int n)
    {
        seg.resize(4 * n);
    }
    void build(int ind, int low, int high, int arr[])
    {
        if (low == high)
        {
            seg[ind] = arr[low];
            return;
        }
        long long mid = (low + high) / 2;
        build(2 * ind + 1, low, mid, arr);
        build(2 * ind + 2, mid + 1, high, arr);
        seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
    }
    long long query(int ind, int low, int high, int l, int r)
    {
        // no overlap
        // l r low high or low high l r
        if (r < low || high < l)
            return 0;
        // complete overlap
        // [l low high r]
        if (low >= l && high <= r)
            return seg[ind];
        long long mid = (low + high) >> 1;
        long long left = query(2 * ind + 1, low, mid, l, r);
        long long right = query(2 * ind + 2, mid + 1, high, l, r);
        return left + right;
    }
    void update(int ind, int low, int high, int i, int val)
    {
        if (low == high)
        {
            seg[ind] = val;
            return;
        }
        long long mid = (low + high) >> 1;
        if (i <= mid)
            update(2 * ind + 1, low, mid, i, val);
        else
            update(2 * ind + 2, mid + 1, high, i, val);
        seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, q, a, b, x, k, u;
    cin >> n >> q;
    int v[n];
    for (int i = 0; i < n; i++)
        cin >> v[i];
    SGTree sg1(n);
    sg1.build(0, 0, n - 1, v);
    while (q--)
    {
        cin >> x;
        // If x == 1 you replace the kth index of array with value u.
        if (x == 1)
        {
            cin >> k >> u;
            k--;
            sg1.update(0, 0, n - 1, k, u);
        }
        else
        {
            // if x == 0 or any other integer then you find the sum of values of the array between indexes a and b.
            cin >> a >> b;
            a--;
            b--;
            cout << sg1.query(0, 0, n - 1, a, b) << "\n";
        }
    }
    return 0;
}
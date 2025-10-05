/**
 * @file SegmentTreeLazyPropagation.cpp
 * @brief Implementation of Segment Tree with Lazy Propagation for Range Updates
 * @author Hacktoberfest Contributor
 * @date October 2025
 *
 * Problem: Efficiently handle range queries and range updates on an array
 *
 * Operations:
 * - Range Sum Query: Find sum of elements in range [L, R]
 * - Range Update: Add a value to all elements in range [L, R]
 * - Point Query: Get value at specific index
 *
 * Algorithm: Segment Tree with Lazy Propagation
 * - Build a binary tree where each node stores aggregate info about a range
 * - Lazy propagation delays updates to children until needed
 * - This avoids updating all affected nodes immediately (O(N) -> O(log N))
 *
 * Key Insight: When updating a range, store the update in node's lazy value
 * and propagate to children only when that subtree is accessed later.
 *
 * Time Complexity:
 * - Build: O(N)
 * - Range Query: O(log N)
 * - Range Update: O(log N)
 * Space Complexity: O(N) - tree needs ~4N nodes
 *
 * Common Interview Questions Using This:
 * - Range sum queries with updates
 * - Range minimum/maximum with updates
 * - Count inversions in dynamic array
 */

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class SegmentTree {
private:
    vector<long long> tree;  // Stores sum for each segment
    vector<long long> lazy;  // Stores pending updates (lazy propagation)
    int n;                   // Size of original array

    /**
     * @brief Push pending updates from parent to children
     * @param node Current node index in tree
     * @param start Start of segment
     * @param end End of segment
     *
     * Lazy propagation logic:
     * 1. Apply pending update to current node
     * 2. If not leaf, pass update to children's lazy values
     * 3. Clear current node's lazy value
     */
    void pushDown(int node, int start, int end) {
        if (lazy[node] != 0) {
            // Apply pending update to current node
            tree[node] += lazy[node] * (end - start + 1);

            // If not leaf, propagate to children
            if (start != end) {
                lazy[2 * node] += lazy[node];
                lazy[2 * node + 1] += lazy[node];
            }

            // Clear lazy value
            lazy[node] = 0;
        }
    }

    /**
     * @brief Build segment tree from array
     * @param node Current node index
     * @param start Start index of segment
     * @param end End index of segment
     * @param arr Original array
     */
    void build(int node, int start, int end, const vector<int>& arr) {
        if (start == end) {
            // Leaf node - store array element
            tree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;

            // Build left and right children
            build(2 * node, start, mid, arr);
            build(2 * node + 1, mid + 1, end, arr);

            // Current node = sum of children
            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
    }

    /**
     * @brief Update range [l, r] by adding value
     * @param node Current node index
     * @param start Start of current segment
     * @param end End of current segment
     * @param l Left bound of update range
     * @param r Right bound of update range
     * @param value Value to add
     */
    void updateRange(int node, int start, int end, int l, int r, long long value) {
        // Push pending updates first
        pushDown(node, start, end);

        // No overlap
        if (start > r || end < l) {
            return;
        }

        // Complete overlap - update lazy value
        if (start >= l && end <= r) {
            lazy[node] += value;
            pushDown(node, start, end);  // Apply immediately
            return;
        }

        // Partial overlap - recurse to children
        int mid = (start + end) / 2;
        updateRange(2 * node, start, mid, l, r, value);
        updateRange(2 * node + 1, mid + 1, end, l, r, value);

        // Update current node after children are updated
        pushDown(2 * node, start, mid);
        pushDown(2 * node + 1, mid + 1, end);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    /**
     * @brief Query sum of range [l, r]
     * @param node Current node index
     * @param start Start of current segment
     * @param end End of current segment
     * @param l Left bound of query range
     * @param r Right bound of query range
     * @return Sum of elements in range [l, r]
     */
    long long queryRange(int node, int start, int end, int l, int r) {
        // No overlap
        if (start > r || end < l) {
            return 0;
        }

        // Push pending updates first
        pushDown(node, start, end);

        // Complete overlap
        if (start >= l && end <= r) {
            return tree[node];
        }

        // Partial overlap - query both children
        int mid = (start + end) / 2;
        long long leftSum = queryRange(2 * node, start, mid, l, r);
        long long rightSum = queryRange(2 * node + 1, mid + 1, end, l, r);

        return leftSum + rightSum;
    }

public:
    /**
     * @brief Constructor - build segment tree from array
     * @param arr Input array
     */
    SegmentTree(const vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n, 0);  // Tree needs ~4N space
        lazy.resize(4 * n, 0);  // Lazy array same size
        build(1, 0, n - 1, arr);
    }

    /**
     * @brief Add value to all elements in range [l, r]
     * @param l Left index (0-based)
     * @param r Right index (0-based)
     * @param value Value to add
     */
    void update(int l, int r, long long value) {
        updateRange(1, 0, n - 1, l, r, value);
    }

    /**
     * @brief Get sum of range [l, r]
     * @param l Left index (0-based)
     * @param r Right index (0-based)
     * @return Sum of elements in range
     */
    long long query(int l, int r) {
        return queryRange(1, 0, n - 1, l, r);
    }

    /**
     * @brief Get value at specific index
     * @param index Index to query
     * @return Value at index
     */
    long long pointQuery(int index) {
        return query(index, index);
    }

    /**
     * @brief Print tree structure (for debugging)
     */
    void printTree() {
        cout << "\nSegment Tree (nodes 1 to " << (4 * n - 1) << "):" << endl;
        for (int i = 1; i < tree.size() && tree[i] != 0; i++) {
            cout << "Node " << i << ": tree=" << tree[i]
                 << ", lazy=" << lazy[i] << endl;
        }
    }
};

/**
 * @brief Segment Tree for Range Minimum Query (RMQ)
 */
class SegmentTreeMin {
private:
    vector<long long> tree;
    vector<long long> lazy;
    int n;

    void pushDown(int node, int start, int end) {
        if (lazy[node] != 0) {
            tree[node] += lazy[node];
            if (start != end) {
                lazy[2 * node] += lazy[node];
                lazy[2 * node + 1] += lazy[node];
            }
            lazy[node] = 0;
        }
    }

    void build(int node, int start, int end, const vector<int>& arr) {
        if (start == end) {
            tree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            build(2 * node, start, mid, arr);
            build(2 * node + 1, mid + 1, end, arr);
            tree[node] = min(tree[2 * node], tree[2 * node + 1]);
        }
    }

    void updateRange(int node, int start, int end, int l, int r, long long value) {
        pushDown(node, start, end);
        if (start > r || end < l) return;

        if (start >= l && end <= r) {
            lazy[node] += value;
            pushDown(node, start, end);
            return;
        }

        int mid = (start + end) / 2;
        updateRange(2 * node, start, mid, l, r, value);
        updateRange(2 * node + 1, mid + 1, end, l, r, value);

        pushDown(2 * node, start, mid);
        pushDown(2 * node + 1, mid + 1, end);
        tree[node] = min(tree[2 * node], tree[2 * node + 1]);
    }

    long long queryRange(int node, int start, int end, int l, int r) {
        if (start > r || end < l) return LLONG_MAX;

        pushDown(node, start, end);

        if (start >= l && end <= r) {
            return tree[node];
        }

        int mid = (start + end) / 2;
        return min(queryRange(2 * node, start, mid, l, r),
                  queryRange(2 * node + 1, mid + 1, end, l, r));
    }

public:
    SegmentTreeMin(const vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n, LLONG_MAX);
        lazy.resize(4 * n, 0);
        build(1, 0, n - 1, arr);
    }

    void update(int l, int r, long long value) {
        updateRange(1, 0, n - 1, l, r, value);
    }

    long long query(int l, int r) {
        return queryRange(1, 0, n - 1, l, r);
    }
};

/**
 * @brief Example usage and test cases
 */
int main() {
    // Test Case 1: Range Sum with Updates
    cout << "=== Test Case 1: Segment Tree - Range Sum ===" << endl;
    vector<int> arr1 = {1, 3, 5, 7, 9, 11};
    SegmentTree st(arr1);

    cout << "Initial array: [1, 3, 5, 7, 9, 11]" << endl;
    cout << "Sum of range [1, 3]: " << st.query(1, 3) << endl;  // 3+5+7 = 15

    cout << "\nAdding 10 to range [1, 3]..." << endl;
    st.update(1, 3, 10);

    cout << "Sum of range [1, 3] after update: " << st.query(1, 3) << endl;  // 13+15+17 = 45
    cout << "Sum of range [0, 5] after update: " << st.query(0, 5) << endl;  // 1+13+15+17+9+11 = 66

    // Test Case 2: Multiple Range Updates
    cout << "\n=== Test Case 2: Multiple Updates ===" << endl;
    vector<int> arr2 = {2, 4, 6, 8, 10};
    SegmentTree st2(arr2);

    cout << "Initial array: [2, 4, 6, 8, 10]" << endl;

    st2.update(0, 2, 5);  // Add 5 to [0, 2]
    st2.update(1, 4, 3);  // Add 3 to [1, 4]

    cout << "After updates:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "arr[" << i << "] = " << st2.pointQuery(i) << endl;
    }
    // Expected: [7, 12, 14, 11, 13]

    // Test Case 3: Range Minimum Query
    cout << "\n=== Test Case 3: Range Minimum Query ===" << endl;
    vector<int> arr3 = {5, 3, 7, 1, 9, 2};
    SegmentTreeMin stMin(arr3);

    cout << "Initial array: [5, 3, 7, 1, 9, 2]" << endl;
    cout << "Min in range [0, 3]: " << stMin.query(0, 3) << endl;  // 1
    cout << "Min in range [2, 5]: " << stMin.query(2, 5) << endl;  // 1

    cout << "\nAdding 10 to range [0, 2]..." << endl;
    stMin.update(0, 2, 10);

    cout << "Min in range [0, 3] after update: " << stMin.query(0, 3) << endl;  // 1
    cout << "Min in range [0, 2] after update: " << stMin.query(0, 2) << endl;  // 13

    // Test Case 4: Large Range Operations
    cout << "\n=== Test Case 4: Efficiency Test ===" << endl;
    vector<int> large(1000, 1);
    SegmentTree stLarge(large);

    cout << "Array size: 1000 elements (all 1s)" << endl;
    cout << "Sum of range [0, 999]: " << stLarge.query(0, 999) << endl;

    stLarge.update(250, 750, 5);  // Add 5 to 501 elements
    cout << "After adding 5 to range [250, 750]:" << endl;
    cout << "Sum of range [0, 999]: " << stLarge.query(0, 999) << endl;
    // 249*1 + 501*6 + 250*1 = 249 + 3006 + 250 = 3505

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

// Node for Huffman Tree
struct Node {
    char ch;
    int freq;
    Node *left, *right;
    Node(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}
};

// Comparator for priority queue
struct compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

// Recursive function to print codes
void printCodes(Node* root, string code) {
    if(!root) return;
    if(!root->left && !root->right) {
        cout << root->ch << ": " << code << endl;
    }
    printCodes(root->left, code + "0");
    printCodes(root->right, code + "1");
}

int main() {
    int n;
    cout << "Enter number of characters: ";
    cin >> n;

    vector<char> chars(n);
    vector<int> freq(n);
    cout << "Enter characters:\n";
    for(int i = 0; i < n; i++) cin >> chars[i];
    cout << "Enter their frequencies:\n";
    for(int i = 0; i < n; i++) cin >> freq[i];

    priority_queue<Node*, vector<Node*>, compare> pq;
    for(int i = 0; i < n; i++) pq.push(new Node(chars[i], freq[i]));

    while(pq.size() > 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();
        Node* merged = new Node('\0', left->freq + right->freq);
        merged->left = left;
        merged->right = right;
        pq.push(merged);
    }

    cout << "Huffman Codes:\n";
    printCodes(pq.top(), "");
    return 0;
}

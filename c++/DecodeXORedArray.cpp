#include <iostream>
using namespace std;
vector<int> decode(vector<int> &encoded, int first)
{
    int n = encoded.size();
    vector<int> code(n + 1);
    code[0] = first;

    for (int i = 0; i < n; i++)
    {
        code[i + 1] = code[i] ^ encoded[i];
    }
    return code;
}
int main()
{
    vector<int> encoded = {1, 2, 3};
    int first = 1;
    cout << "Decode XORed Array : " << endl;
    vector<int> ans = decode(encoded, first);
    for (auto num : ans)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
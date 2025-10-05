#include <iostream>
using namespace std;
// Brute force solution
string decimaToBinary(int num)
{
    int n = num;
    string ans = "";

    while (n > 0)
    {
        if (n % 2 == 1)
        {
            ans += '1';
        }
        else
        {
            ans += '0';
        }
        n /= 2;
    }

    return ans;
}
int binaryGapBrute(int n)
{
    string binary = decimaToBinary(n);
    int previous = 0;
    int maxDist = 0;
    for (int i = 1; i < binary.size(); i++)
    {
        if (binary[i] == '1' && binary[previous] == '1')
        {
            maxDist = max(maxDist, i - previous);
            previous = i;
        }
        if (binary[i] == '1')
        {
            previous = i;
        }
    }
    return maxDist;
}
// Optimal solution
int binaryGapOptimal(int n)
{
    int last = -1;
    int idx = 0;
    int maxDist = 0;
    while (n > 0)
    {
        if (n & 1)
        {
            if (last != -1)
            {
                maxDist = max(maxDist, idx - last);
            }
            last = idx;
        }
        idx++;
        n >>= 1;
    }
    return maxDist;
}
int main()
{
    cout << "Binary Gap : " << binaryGapBrute(13) << endl;
    cout << "Binary Gap : " << binaryGapOptimal(13) << endl;

    return 0;
}
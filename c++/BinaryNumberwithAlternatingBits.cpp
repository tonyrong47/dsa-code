#include <iostream>
using namespace std;
// Bture foce solution
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
    reverse(ans.begin(), ans.end());
    return ans;
}
bool hasAlternatingBitsBture(int n)
{
    string bits = decimaToBinary(n);

    for (int i = 1; i < bits.size(); i++)
    {
        if (bits[i] == bits[i - 1])
        {
            return false;
        }
    }
    return true;
}
// Optimal solution
bool hasAlternatingBitsOptimal(int n)
{
    int previousBit = INT_MAX;

    while(n > 0){
        int digit = n % 2;
        if(previousBit == digit) return false;
        previousBit = digit;
        n /= 2;
    }
    return true;
}
int main()
{
    cout << "Binary Number with Alternating Bits : " << hasAlternatingBitsBture(7) << endl;
    cout << "Binary Number with Alternating Bits : " << hasAlternatingBitsOptimal(7) << endl;

    return 0;
}
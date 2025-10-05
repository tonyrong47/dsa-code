#include <iostream>
using namespace std;

string decimaToBinary(int num)
{
    int n = num;
    string ans = "";

    while (n > 0)
    {
        if(n % 2 == 1) ans += '1';
        else ans += '0';
        n /= 2;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
int main()
{
    int num = 11;
    cout << "Decima To Binary : " << decimaToBinary(num) << endl;
    return 0;
}
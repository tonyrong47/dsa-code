#include <iostream>
using namespace std;

int rangeBitwiseAndBrute(int left, int right)
{
    while (left < right)
    {
        right = (right & (right - 1));
    }

    return right;
}
int rangeBitwiseAndOptimal(int left, int right)
{
    int shift = 0;
    while (left < right)
    {
        left >>= 1;
        right >>= 1;
        shift++;
    }
    return left << shift;
}
int main()
{
    int left = 1, right = 2147483647;
    cout << "range Bitwise And : " << rangeBitwiseAndBrute(left, right) << endl;
    cout << "range Bitwise And : " << rangeBitwiseAndOptimal(left, right) << endl;
    return 0;
}
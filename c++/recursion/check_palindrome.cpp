#include<iostream.h>
using namespace std;
int reverse(int n,int rev=0)
{
    if(n==0)
    return rev;
    rev=n%10+rev*10;
    reverse(n/10,rev);
}
void palin(int n)
{
    if(n<0)
    return;
    int x=reverse(n);
    if(x==n)
    cout<<"number is palindrome ";
    else
    cout<<"number is not a palindrome ";
}
int main()
{
    int n;
    cout<<"enter a number \n";
    cin>>n;
    palin(n);
    return 0;
}
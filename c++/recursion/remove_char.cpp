#include<iostream.h>
using namespace std;
string removestr(string &str,int n,int x)
{
    if(n==x)
    return "";
    string curr="";
    curr+=str[n];
    return ((str[n]=='a')?"":curr)+removestr(str,n+1,x);
}
int main()
{
    string str="abcax";
    int n=5;
    cout<<"string is \n";
    cout<<removestr(str,0,n);
    return 0;
}
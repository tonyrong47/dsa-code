#include<iostream.h>
using namespace std;
int gcf(int x,int y)
{
    if(y>x)
    return gcf(y,x);
    if(y==0)
    return x;
    return gcf(y,x%y);
}
int main()
{
    int x,y;
    cout<<"enter the value of x and y \n";
    cin>>x>>y;
    int m= gcf(x,y);
    cout<<"greatest common factor \n"<<m;
    return 0;
}
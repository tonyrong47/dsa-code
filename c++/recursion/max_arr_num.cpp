#include<iostream.h>
using namespace std;
int maxrec(int *a,int n,int x)
{
  if(n==x-1)
  return a[n];
  int m=0;
  //sum of array
  m=a[n]+maxrec(a,n+1,x);


  // maximum number in array
  // m=max(a[n],maxrec(a,n+1,x));

  
  return m;
}
int main()
{
    int n;
    cout<<"enter thr value of n \n";
    cin>>n;
    cout<<"enter array elements \n";
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    int x= maxrec(a,0,n);
    cout<<"maximum nos is \n"<<x;
    return 0;
}
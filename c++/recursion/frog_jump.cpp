#include<bits/stdc++.h>
using namespace std;
int find(vector<int>&v,int n,int i)
{
    if(i==n-1)return 0;
    if(i==n-2)return find(v,n,i+1)+ abs(v[i]-v[i+1]);
    return min(find(v,n,i+1)+abs(v[i]-v[i+1]),find(v,n,i+2)+abs(v[i]-v[i+2]));
}
int main()
{
    int n;
    cout<<"enter the value of n\n";
    cin>>n;
    cout<<"enter hieghts of brick\n";
    vector<int>vec(n);
    for(int i=0;i<n;i++)
    cin>>vec[i];
    int x=find(vec,n,0);
    cout<<"minimum cost is \n"<<x;
    return 0;
}
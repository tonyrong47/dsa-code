// Given a 3-Dimensional array of integers A[L][R][C], where L, R, and C are dimensions of the array (Layer, Row, Column). Find the prefix sum 3d array for it. Let the Prefix sum 3d array be arr[L][R][C]. Here arr[k][i][j]  gives the sum of all integers between arr[0][0][0] and arr[k][i][j] (including both).

#include <bits/stdc++.h>
using namespace std;
#define L 4
#define R 4
#define C 4
void prefixSum3D(int A[L][R][C]) {
    int arr[L][R][C];
    arr[0][0][0]=A[0][0][0];
    for(int i=1;i<L;i++) arr[i][0][0]=arr[i-1][0][0]+A[i][0][0];
    for(int i=1;i<R;i++) arr[0][i][0]=arr[0][i-1][0]+A[0][i][0];
    for(int i=1;i<C;i++) arr[0][0][i]=arr[0][0][i-1]+A[0][0][i];
    for(int k=1;k<L;k++) for(int i=1;i<R;i++) arr[k][i][0]=A[k][i][0]+arr[k-1][i][0]+arr[k][i-1][0]-arr[k-1][i-1][0];
    for(int i=1;i<R;i++) for(int j=1;j<C;j++) arr[0][i][j]=A[0][i][j]+arr[0][i-1][j]+arr[0][i][j-1]-arr[0][i-1][j-1];
    for(int j=1;j<C;j++) for(int k=1;k<L;k++) arr[k][0][j]=A[k][0][j]+arr[k-1][0][j]+arr[k][0][j-1]-arr[k-1][0][j-1];
    for(int k=1;k<L;k++) {
        for(int i=1;i<R;i++) {
            for(int j=1;j<C;j++) {
                arr[k][i][j]=A[k][i][j]+arr[k-1][i][j]+arr[k][i-1][j]+arr[k][i][j-1]-arr[k-1][i-1][j]-arr[k][i-1][j-1]-arr[k-1][i][j-1]+arr[k-1][i-1][j-1];
            }
        }
    }
    for(int k=0;k<L;k++) {
        cout<<"Layer "<<k+1<<':'<<endl;
        for(int i=0;i<R;i++) {
            for(int j=0;j<C;j++) {
                cout<<arr[k][i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
}
int main() {
    int A[L][R][C]={
        {{1,1,1,1},{1,1,1,1},{1,1,1,1},{1,1,1,1}},
        {{1,1,1,1},{1,1,1,1},{1,1,1,1},{1,1,1,1}},
        {{1,1,1,1},{1,1,1,1},{1,1,1,1},{1,1,1,1}},
        {{1,1,1,1},{1,1,1,1},{1,1,1,1},{1,1,1,1}}
    };
    prefixSum3D(A);
    return 0;
}
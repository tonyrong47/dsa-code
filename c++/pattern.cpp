#include <iostream>
using namespace std;

void binaryflip(int n){
    
    int start = 1;

    for(int i=0;i<n;i++){
        if(start % 2 == 0) start = 0;
        for(int j=0;j<i;j++){
            start = 1 - start;
            cout<<start;
        }
        cout<<endl;
    }
}

int main(){

    int n;
    cin>>n;
    binaryflip(n);
    
    return 0;
}
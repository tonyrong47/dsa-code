#include <iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
  
    
    if (n<=5)
    {
        cout<<n+1;
        n = n + 1;
    }
    else {
        cout<<"Not Valid"; 
    }
return 0;
}
#include<bits/stdc++.h>
using namespace std;

vector<int> decimalRepresentation(int n) {
    vector<int> ans;
    long long i = 1;
    if(n==0){
        ans.push_back(0);
        return ans;
    }
    while(n>0){
        int last_digit = n%10;
        if(last_digit!=0){
            ans.push_back(last_digit*i);
        }
            
        i = i * 10;
        n = n/10;
    }
    reverse(ans.begin(),ans.end());
    return ans;

}


int main(){
    int n;
    cin >> n;
    vector<int> result = decimalRepresentation(n);
    for(int i:result){
        cout << i << " ";
    }

}
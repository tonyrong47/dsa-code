// Leetcode 218 [The Skyline Problem]


#include <bits/stdc++.h>
using namespace std;
struct Event{
    int x,h,type;
    bool operator<(const Event &e) const{return x<e.x||(x==e.x&&type<e.type)||(x==e.x&&type==e.type&&h>e.h);}
};
vector<vector<int>> getSkyline(vector<vector<int>> &b){
    vector<Event> ev;
    for(auto &a:b){
        ev.push_back({a[0],a[1],0});
        ev.push_back({a[2],a[1],1});
    }
    sort(ev.begin(),ev.end());
    multiset<int> ms;
    ms.insert(0);
    int prev=0;
    vector<vector<int>> res;
    for(auto &e:ev){
        if(e.type==0)ms.insert(e.h);
        else ms.erase(ms.find(e.h));
        int cur=*ms.rbegin();
        if(cur!=prev){
            res.push_back({e.x,cur});
            prev=cur;
        }
    }
    return res;
}
int main(){
    int n;
    cin>>n;
    vector<vector<int>> b(n,vector<int>(3));
    for(int i=0;i<n;i++)
        for(int j=0;j<3;j++)
            cin>>b[i][j];
    vector<vector<int>> res=getSkyline(b);
    for(auto &a:res)
        cout<<a[0]<<" "<<a[1]<<endl;
}

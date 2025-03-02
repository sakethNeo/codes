/*
ID: sakethx1
TASK: ride
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,popcnt")

int main() {
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");
    int t; cin>>t;
    unordered_map<string,int> mp;
    string a[t];
    for(int i=0;i<t;i++){
        cin>>a[i];
    }
    for(int i=0;i<t;i++){
        int am,num; cin>>am>>num;
        string s; cin>>s; int k=am/num;
        mp[s]-=k*num;
        for(int i=0;i<num;i++){
            cin>>s;
            mp[s]+=k;
        }
    }
    for(auto i:a){
        cout<<i<<" "<<mp[i]<<"\n";
    }
    return 0;
}
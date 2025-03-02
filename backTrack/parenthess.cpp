#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<string> res;
void func(string &s,int op,int cl,int n){
    if(op==n && cl==n){
        res.push_back(s); return;
    }
    if(op<n){
        s.push_back('('); func(s,op+1,cl,n);
        s.pop_back();
    }
    if(cl<n){
        if(op>cl){
            s.push_back(')'); func(s,op,cl+1,n);
            s.pop_back();
        }
    }
}
vector<string> genPar(int n){
    string s;
    func(s,0,0,n);
    return res;
}

void solve(){
    auto ans=genPar(3);
    for(auto i:ans) cout<<i<<" ";
    cout<<"\n";
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--) solve();
    return 0;
}
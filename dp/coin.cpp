#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int dp[N];

int func(int amount,vector<int>&coins){
    if(amount==0) return 0;
    if(dp[amount]!=-1) return dp[amount];
    int ans=INT_MAX;
    for(int coin:coins){
        if(amount>=coin) ans=min(ans+0LL,func(amount-coin,coins)+1LL);
    }
    return dp[amount]=ans;
}

int main(){
    memset(dp,-1,sizeof(dp));
    int n,k;
    cin>>n;
    vector<int> a;
    for(int i=0;i<n;i++){
        cin>>k;
        a.push_back(k);
    }
    int amount;
    cin>>amount;
    cout<<func(amount,a);
}
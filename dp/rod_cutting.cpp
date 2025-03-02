#include<bits/stdc++.h>
using namespace std;
const int MAX=1e5;
const int N=1e3;
const int M=105;
int dp[N];
int p[N];

int func(int n){
    if(n==0) return 0;
    if(dp[n]!=-1) return dp[n];
    int ans=0;
    for(int i=0;i<n;i++){
        ans=max(ans,p[i]+func(n-i-1));
    }
    return dp[n]=ans;
}

int main(){
    memset(dp,-1,sizeof(dp));
    int n;cin>>n;
    for(int i=0;i<n;i++) cin>>p[i];
    cout<<func(n);
    return 0;
}
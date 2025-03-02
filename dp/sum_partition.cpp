#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int dp[N][N];
int a[N];

int func(int idx,int sum){
    if(sum==0) return 1;
    if(idx<=0) return 0;
    if(dp[idx][sum]!=-1) return dp[idx][sum];
    int ans=func(idx-1,sum);
    if(sum>=a[idx]) ans=max(ans,func(idx-1,sum-a[idx]));
    return dp[idx][sum]=ans;
}

int main(){
    memset(dp,-1,sizeof(dp));
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    int sum=accumulate(a,a+n,0);
    if(sum%2) cout<<0<<"\n";
    else cout<<func(n-1,sum/2)<<"\n";
    return 0;
}
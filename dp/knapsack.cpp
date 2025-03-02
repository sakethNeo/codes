#include <bits/stdc++.h>
using namespace std;
const int MAX=2e5+10;
const int N=1e5+10;
const int M=105;
int w[M],v[M];
long long dp[M][N];

long long func(int ind,int wt){
    if(wt==0) return 0;
    if(ind<0) return 0;
    if(dp[ind][wt]!=-1) return dp[ind][wt];
    long long ans=func(ind-1,wt);
    if(wt>=w[ind]) ans=max(ans,func(ind-1,wt-w[ind])+v[ind]);
    return dp[ind][wt]=ans;
}

int main(){
    memset(dp,-1,sizeof(dp));
    int n,wt;
    cin>>n>>wt;
    for(int i=0;i<n;i++){
        cin>>w[i]>>v[i];
    }
    cout<<func(n-1,wt);
    return 0;
}
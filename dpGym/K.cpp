#include <bits/stdc++.h>
using namespace std;

#define int long long
const int mod=1e9+7;
const int inf=1e18;

int n,k;
vector<vector<int>> dp(2001,vector<int>(2001,-1));

int cal(int i,int val){
    if(i==k-1) return 1;
    if(~dp[i][val]) return dp[i][val];
    int ans=0;
    for(int j=1;j*val<=n;j++){
        ans+=cal(i+1,val*j);
    }
    return dp[i][val]=ans;
}

inline void solve() {
    cin>>n>>k;

    int ans=0;
    for(int i=0;i<=n;i++)
        for(int j=0;j<=k;j++) dp[j][i]=0;

    for(int i=1;i<=n;i++) dp[k-1][i]=1;

    for(int i=k-2;i>=0;i--){
        for(int j=1;j<=n;j++){
            for(int k=1;k*j<=n;k++){
                dp[i][j]+=dp[i+1][j*k];
            }
        }
    }

    for(int i=1;i<=n;i++) ans+=dp[0][i];
    cout<<ans<<"\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int32_t t=1;
    // cin>>t;
    while(t--) solve();

    return 0;
}

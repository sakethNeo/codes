#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N];
int dp[N];
// int min(int a,int b){
//     return a>b ? b:a;
// }


int frog(int n){
    if(n==0) return 0;
    if(dp[n]!=-1) return dp[n];
    int cost=INT_MAX;
    cost=min(cost,abs(a[n]-a[n-1])+frog(n-1));
    if(n>1) cost=min(cost,abs(a[n]-a[n-2])+frog(n-2));
    return dp[n]=cost;
}

int main(){
    memset(dp,-1,sizeof(dp));
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<frog(n-1)<<"\n";
    return 0;
}
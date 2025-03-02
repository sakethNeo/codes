#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
const int INF=1e9+10;
const int n=101;
#define vi vector<int>
#define pi pair<int,int>
#define vpi vector<pair<int,int>>
#define ff first
#define ss second
#define pb push_back
#define all(v) v.begin(),v.end()
int dp[n][n];

void reset(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j) dp[i][j]=0;
            else dp[i][j]=INF;
        }
    }
}

int main(){
    reset();
    int v,e;
    cin>>v>>e;
    for(int i=0;i<e;i++){
        int v1,v2,wt;
        cin>>v1>>v2>>wt;
        dp[v1][v2]=wt;
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
            }
        }
    }
    for(int i=1;i<=v;i++){
        for(int j=1;j<=v;j++){
            if(dp[i][j]==INF) cout<<"I ";
            else cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
/*
6 9
1 2 1
1 3 5
2 3 2
3 5 2
2 5 1
2 4 2
4 5 3
4 6 1
5 6 2
*/
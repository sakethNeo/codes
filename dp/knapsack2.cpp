#include<bits/stdc++.h>
using namespace std;
long long t,m,x,c[55],h[55],dp[100005];
int main(){
	cin>>t;
	while(t--){
		cin>>m>>x;
		long long sum=0,ans=0;
		for(int i=1;i<=m;i++){
			cin>>c[i]>>h[i];
			sum+=h[i];
		}
		memset(dp,0x3f,sizeof(dp));
		dp[0]=0;
		for(long long i=1;i<=m;i++){
			for(long long j=sum;j>=h[i];j--){
				if(dp[j-h[i]]+c[i]<=x*(i-1)){
					dp[j]=min(dp[j],dp[j-h[i]]+c[i]);
					ans=max(ans,j);
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
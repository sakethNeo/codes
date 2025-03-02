#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N];
int dp[N];

int lis(int n){
    if(dp[n]!=-1) return dp[n];
    int ans=1;
    for(int i=0;i<n;i++){
        if(a[n]>a[i]) ans=max(ans,lis(i)+1);
    }
    return dp[n]=ans;
}  

int longestIncreasingSubsequenceBS(const vector<int>& nums) {
    vector<int> tails; // Maintain a sorted list of tails

    for (int num : nums) {
        int left = 0, right = tails.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (tails[mid] < num) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        if (right == tails.size()) {
            tails.push_back(num);
        } else {
            tails[right] = num;
        }
    }

    return tails.size();
}

int main(){
    memset(dp,-1,sizeof(dp));
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    int ans=0;
    for(int i=0;i<n;i++){
        ans=max(ans,lis(i));
    }
    cout<<ans;
    return 0;
}


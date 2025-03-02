#include <bits/stdc++.h>
using namespace std;

vector<int> nxt(vector<int> &nums){
    int n=nums.size(); 
    int k=n-2;
    while(k>=0 && nums[k+1]<=nums[k]) k--;
    if(k>=0){
        int l=n-1;
        while(nums[l]<=nums[k]) l--;
        swap(nums[l],nums[k]);
    } 
    reverse(nums.begin()+k+1,nums.end());
    return nums;
}

signed main(){
    vector<int> ans,nums={1,3,2};
    ans=nxt(nums);
    for(auto i:ans) cout<<i<<" "; cout<<"\n";
    return 0;
}

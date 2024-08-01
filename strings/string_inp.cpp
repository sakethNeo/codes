#include<bits/stdc++.h>
using namespace std;

#define int long long
const int mod=1e9+7;
const int inf=1e18;


signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	string in;
	getline(cin,in);
	stringstream s(in);
	int num;
	vector<int> arr;
	while(s>>num) arr.push_back(num);
	for(auto i:arr) cout<<i<<" ";

    return 0;
}

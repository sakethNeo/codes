#include<bits/stdc++.h>
using namespace std;

#define int long long
const int mod=1e9+7;
const int inf=1e18;

class Median{
	multiset<int> l,r;
	private:
		void adjust(){
			if(r.size()>l.size()){
				l.insert(*r.begin());
				r.erase(r.begin());	
			}
			else if(l.size()-r.size()>1){
				r.insert(*l.rbegin());
				l.erase(prev(l.end()));
			}
		}
	public:
		void add(int vl){
			if(l.empty()) return l.insert(vl), (void)0;
			if(vl>*l.rbegin()) r.insert(vl);
			else l.insert(vl);
			adjust();
		}
		void erase(int vl){
			if(l.find(vl)!=l.end()) l.erase(l.find(vl));
			else r.erase(r.find(vl));
			adjust();
		}
		int get(){
			return *l.rbegin();
		}
};

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
    

    return 0;
}

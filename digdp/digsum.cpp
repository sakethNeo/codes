#include <bits/stdc++.h>
using namespace std;


signed main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k;
    int L,R;
    cin>>L>>R>>k;
    L--;
    string l=to_string(L),r=to_string(R);
    function<int(string&,int,int,bool)> digs=[&](string &s,int n,int x,bool t)->int {
        if(x<0) return 0;
        if(n==0) return (x==0);
        int ub=(t)? s[s.size()-n]-'0':9;
        int ans=0;
        for(int i=0;i<=ub;i++){
            ans+=digs(s,n-1,x-i,t&(i==ub));
        }
        return ans;
    };

    auto br=[&](int l,int r,int k){
        int ans=0;
        for(int i=l+1;i<=r;i++){
            int s=0,t=i;
            while(t){
                s+=(t%10);
                t/=10;
            }
            if(s==k) ans++;
        }
        return ans;
    };

    cout<<br(L,R,k)<<endl;
    cout<<digs(l,l.size(),k,true)<<" "<<digs(r,r.size(),k,true);

    return 0;
}

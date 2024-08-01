#include <bits/stdc++.h>
using namespace std;

#define int long long
const int mod=1e9+7;

int gcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}



inline int ml(int a,int b){
    return ((a%mod)*(b%mod))%mod;
}


inline int ad(int a,int b){
    return ((a%mod)+(b%mod))%mod;
}

inline int sb(int a,int b){
    return ((a-b)%mod+mod)%mod;
}
inline int pw(int n,int x){
    int res=1;
    while(x){
        if(x&1) res=(res*n)%mod;
        n=(n*n)%mod;
        x>>=1;
    }
    return res;
}
inline int invMod(int n){
    return pw(n,mod-2);
}

inline int dv(int a,int b){
    return (a*invMod(b))%mod;
}

inline int C(int n,int r){
    if(r>n) return 0LL;
    if(n-r>r) return C(n,n-r);
    int res=1;
    int inv=1;
    for(int i=r+1;i<=n;i++){
        res=(res*i)%mod;
        inv=(inv*invMod(i-r))%mod;
    }
    return (res*inv)%mod;
}

signed main(){
        
    return 0;
}
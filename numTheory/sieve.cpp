#include <bits/stdc++.h>
using namespace std;
const int N=1e7+5;
const int mod=1e9+7;
vector<bool> isPrime(N,1);
vector<int> highestPrime(N,0),lowestPrime(N,0);
vector<int> primes;

// seive to find primes and lowest prime factor and highest prime factor of a given number
void seive(){
    isPrime[0]=isPrime[1]=0;
    for(int i=2;i<N;i++){
        if(isPrime[i]){
            lowestPrime[i]=highestPrime[i]=i;
            for(int j=2*i;j<N;j+=i){
                isPrime[j]=0;
                highestPrime[j]=i;
                if(lowestPrime[j]==0) lowestPrime[j]=i;
            }
            primes.push_back(i);
        }
    }
}

vector<int> p;
void Seive(int n){
    vector<bool> isp(n+1,true);
    for(int i=2;i<=n;i++){
        if(isp[i]) p.push_back(i);
        for(int j=2*i;j<=n;j+=i) isp[j]=false;
    }
}

// to find prime factors
vector<int> pf(int n){
    vector<int> ans; // or use map to store prime_factor and count
    while(n>1){
        int f=highestPrime[n];
        while(n%f==0){
            n/=f; ans.push_back(f);
        }
    }
    return ans;
}

// to find divisors
vector<int> divisors[N];
void func(){
    for(int i=2;i<N;i++){
        for(int j=i;j<N;j+=i){
            divisors[j].push_back(i);
        }
    }
}

inline vector<int> div(int n){
    vector<int> d;
    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            d.push_back(i);
            if(n/i!=i){
                d.push_back(n/i);
            }
        }
    }
    sort(d.begin(),d.end());
    return d;
}

inline vector<int> f(int x){
    vector<int> p;
    int t=x;
    for(auto i:primes){
        if(i*i>t) break;
        if(x%i==0){
            int c=0;
            while(x%i==0){
                c++;
                x/=i;
            }
            p.push_back(c);
        }
    }
    if(isPrime[x]) p.push_back(1);
    return p;
}

int main(){
    seive();
    
    return 0;
}
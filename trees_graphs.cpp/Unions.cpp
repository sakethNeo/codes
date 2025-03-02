#include<bits/stdc++.h>
using namespace std;

class DSU {
    int n, sz;
    vector<int> p, s;
public:
    DSU(int n) : n(n), sz(n), p(n), s(n, 1) {
        iota(p.begin(), p.end(), 0);
    }
    int find(int x) {
        if (p[x] == x) return x;
        return p[x] = find(p[x]);
    }
    bool merge(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return false;
        if (s[x] > s[y]) swap(x, y);
        p[x] = y, s[y] += s[x];
        sz--;
        return true;
    }
    int size() {
        return sz;
    }
    auto connected_components() {
        vector<vector<int>> v(sz);
        map<int, int> mp;
        int id = 0;
        for (int i = 0; i < n; i++) {
            mp[find(i)] = id++;
        }
        for (int i = 0; i < n; i++) {
            v[mp[find(i)]].push_back(i);
        }
        return v;
    }
};

class DSU{
    int n;
    vector<int> s,p;
    public:
        DSU(int n): n(n), s(n+1,1), p(n+1) {
            iota(p.begin(),p.end(),0);
        }   
        int find(int v){
            if(p[v]==v) return v;
            return p[v]=find(p[v]);
        }
        bool usize(int a,int b){
            a=find(a),b=find(b);
            if(a==b) return false;
            if(s[a]>s[b]) swap(a,b);
            p[a]=b;
            s[b]+=s[a];
            return true;
        }
        set<int> uset(){
            set<int> st;
            for(int i=1;i<=n;i++) st.insert(find(i));
            return st;
        }
};

class DSU{
    int n;
    vector<int> s,p;
    public:
        DSU(int n): n(n), s(n,1), p(n) {
            iota(p.begin(),p.end(),0);
        }   
        int find(int v){
            if(p[v]==v) return v;
            return p[v]=find(p[v]);
        }
        bool usize(int a,int b){
            a=find(a),b=find(b);
            if(a==b) return false;
            if(s[a]>s[b]) swap(a,b);
            p[a]=b;
            s[b]+=s[a];
            return true;
        }
        set<int> uset(){
            set<int> st;
            for(int i=0;i<n;i++) st.insert(find(i));
            return st;
        }
};

struct DSU {
    vector<int> parent,size,rank;

    DSU(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        rank.resize(n + 1, 0);
        for (int i = 1; i <= n; i++) parent[i] = i;
    }

    int find(int v) {
        if (parent[v] == v) return v;
        return parent[v] = find(parent[v]);
    }

    bool usize(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return false; 
        if (size[a] < size[b]) swap(a, b);
        parent[b] = a;
        size[a] += size[b];
        return true; 
    }

    bool urank(int a,int b) {
        a = find(a);
        b = find(b);
        if (a == b) return false;
        if (rank[a] < rank[b]) swap(a, b);
        if (rank[a] == rank[b]) rank[a]++;
        parent[b] = a;
        return true;
    }
};




int main(){

    return 0;
}
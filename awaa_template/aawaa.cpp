#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<iomanip>
#include<cstdlib>
#define _t putchar(32)
#define _e putchar(10)
#define inf 2147483647
#define ine -2147483647
#define lb(x) ((x)&(-x))
#define sp(x,y) x^=y^=x^=y
using namespace std;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

template<class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template<class K, class V>
using ordered_map = tree<K, V, std::less<K>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
bool o;
char ch,ss[1<<17],*A=ss,*B=ss;
inline char gc(){
	return A==B&&(B=(A=ss)+fread(ss,1,1<<17,stdin),A==B)?EOF:*A++;
}
template <typename _Tp> inline void rd(_Tp &x);
template <typename _Tp> inline void wr(_Tp x);
template <typename _Tp> inline _Tp mx(_Tp x,_Tp y);
template <typename _Tp> inline _Tp mn(_Tp x,_Tp y);
int n,m,v[200001];
struct p{
	int x,y,v;
	friend bool operator<(p i,p j){
		return i.v<j.v;
	}
}a[200001];
ll ans[200001],s[200001];
int f[200001],x;
inline int find(int x){
	return x==f[x]?x:f[x]=find(f[x]);
}
int main(){
	rd(n);
	rd(m);
	for(int i=1;i<n;i++){
		rd(a[i].x);
		rd(a[i].y);
		rd(a[i].v);
	}
	for(int i=1;i<=n;i++)
	f[i]=i,s[i]=1;
	sort(a+1,a+n);
	for(int i=1;i<n;i++){
		a[i].x=find(a[i].x);
		a[i].y=find(a[i].y);
		ans[i]=ans[i-1]+s[a[i].x]*s[a[i].y];
		s[a[i].y]+=s[a[i].x];
		f[a[i].x]=a[i].y;
		v[i]=a[i].v;
	}
	while(m--){
		rd(x);
		x=upper_bound(v+1,v+n,x)-v-1;
		wr(ans[x]),_t;
	}
}

template <typename _Tp>
    inline void rd(_Tp &x){
    	o=0;
        x=0;
      	while (ch^45&&(ch<48||ch>57)) ch=gc();
      	if(ch==45)o=1,ch=gc();
        while(ch>47&&ch<58){
			x=(x<<1)+(x<<3)+(ch^48);
			ch=gc();
		}
      	if(o) x=-x;
 	}
template <typename _Tp>
    inline void wr(_Tp x){
        if(x<0) x=-x,putchar(45);
        if(x<10){
            putchar(x+48);
            return;
        }
        wr(x/10);
        putchar(x%10+48);
    }
template <typename _Tp>
	inline _Tp mx(_Tp x,_Tp y){
		return x>y?x:y;
	}
template <typename _Tp>
	inline _Tp mn(_Tp x,_Tp y){
		return x<y?x:y;
	}


class fastIO {
private:
    char ibuf[50007], *p1 = ibuf, *p2 = ibuf, obuf[50007], *p3 = obuf, sta[50];
    bool file_end = false;
    char get() {
        return p1 == p2 && (p2 = (p1 = ibuf) + fread(ibuf, 1, 50007, stdin), p1 == p2) ? (file_end = true), char(EOF): *p1++;
    }
    void put(const char x) {
        p3 - obuf < 50007 ? *p3 ++ = x : (fwrite(obuf, p3 - obuf, 1, stdout), p3 = obuf, *p3++ = x);
    }
public:
    explicit operator bool() { return !file_end; }
    size_t flush() {
        size_t f = fwrite(obuf, p3 - obuf, 1, stdout);
        p3 = obuf;
        *p3 = 0;
        return f;
    }
    fastIO &operator>>(char &t) {
        for (t = get(); !isgraph(t); t = get());
        return *this;
    }
    template<typename any>
    typename enable_if<is_same<any, char>::value, any>::type tpval() {
        char t;
        for (t = get(); !isgraph(t); t = get());
        return t;
    }
    fastIO &operator>>(char *t) {
        char c;
        for (c = get(); !isgraph(c); c = get());
        for (; isgraph(c); c = get())*t = c, t++;
        *t = 0;
        return *this;
    }
    fastIO &operator>>(string &t) {
        t.clear();
        char c;
        for (c = get(); !isgraph(c); c = get());
        for (; isgraph(c); c = get())t += c;
        return *this;
    }
    template<typename any>
    typename enable_if<is_same<any, string>::value, any>::type tpval() {
        string t;
        char c;
        for (c = get(); !isgraph(c); c = get());
        for (; isgraph(c); c = get())t += c;
        return t;
    }
    template<typename any>
    typename enable_if<
            (is_signed<any>::value && is_integral<any>::value && !is_same<any, char>::value) ||
            is_same<any, __int128_t>::value, fastIO>::type &operator>>(any &t) {
        t = 0;
        bool y = 0;
        char c = get();
        for (; !isdigit(c); c = get())if (c == 45)y = true;
        for (; isdigit(c); c = get())t = t * 10 + c - 48;
        if (y == 1)t = -t;
        return *this;
    }
    template<typename any>
    typename enable_if<
            (is_signed<any>::value && is_integral<any>::value && !is_same<any, char>::value) ||
            is_same<any, __int128_t>::value, any>::type tpval() {
        any t = 0;
        bool y = 0;
        char c = get();
        for (; !isdigit(c); c = get())if (c == 45)y = true;
        for (; isdigit(c); c = get())t = t * 10 + c - 48;
        if (y == 1)t = -t;
        return t;
    }
    template<typename any>
    typename enable_if<
            (is_unsigned<any>::value && is_integral<any>::value && !is_same<any, char>::value) ||
            is_same<any, __uint128_t>::value, fastIO>::type &operator>>(any &t) {
        t = 0;
        char c = get();
        for (; !isdigit(c); c = get());
        for (; isdigit(c); c = get())t = t * 10 + c - 48;
        return *this;
    }
    template<typename any>
    typename enable_if<
            (is_unsigned<any>::value && is_integral<any>::value && !is_same<any, char>::value) ||
            is_same<any, __uint128_t>::value, any>::type tpval() {
        any t = 0;
        char c = get();
        for (; !isdigit(c); c = get());
        for (; isdigit(c); c = get())t = t * 10 + c - 48;
        return t;
    }
    template<typename any1, typename any2>
    fastIO &operator>>(pair<any1, any2> &t) { return *this >> t.first >> t.second; }
    template<typename any1, typename any2>
    pair<any1, any2> tpval() { return pair<any1, any2>(tpval<any1>(), tpval<any2>()); }
    template<typename any>
    fastIO &read(any &t) { return *this >> t; }
    fastIO &read(char *t) {
        char c;
        for (c = get(); !isgraph(c); c = get());
        for (; isgraph(c); c = get())*t = c, t++;
        *t = 0;
        return *this;
    }
    template<typename any, typename...args>
    fastIO &read(any &t1, args &...t2) { return (*this >> t1).read(t2...); }
    fastIO &operator<<(const char t) {
        put(t);
        return *this;
    }
    fastIO &operator<<(const char *t) {
        for (; *t; t++)put(*t);
        return *this;
    }
    fastIO &operator<<(const string &t) {
        for (const char it: t)put(it);
        return *this;
    }
    template<typename any>
    typename enable_if<
            (is_signed<any>::value && is_integral<any>::value && !is_same<any, char>::value) ||
            is_same<any, __int128_t>::value, fastIO>::type &operator<<(any t) {
        if (!t) {
            put(48);
            return *this;
        }
        int len = 0;
        if (t < 0)t = -t, put(45);
        while (t)sta[len++] = char(t % 10 + 48), t /= 10;
        while (len--)put(sta[len]);
        return *this;
    }
    template<typename any>
    typename enable_if<
            (is_unsigned<any>::value && is_integral<any>::value && !is_same<any, char>::value) ||
            is_same<any, __uint128_t>::value, fastIO>::type &operator<<(any t) {
        if (!t) {
            put(48);
            return *this;
        }
        int len = 0;
        while (t)sta[len++] = char(t % 10 + 48), t /= 10;
        while (len--)put(sta[len]);
        return *this;
    }
    template<typename any1, typename any2>
    fastIO &operator<<(const pair<any1, any2> &t) { return *this << t.first << ' ' << t.second; }
    template<typename any>
    fastIO &write(const any &t) { return *this << t; }
    template<typename any, typename...args>
    fastIO &write(const any &t1, const args &...t2) { return (*this << t1).write(t2...); }
 
    ~fastIO() { fwrite(obuf, p3 - obuf, 1, stdout); }
}FastIO;
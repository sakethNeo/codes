// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")

// use either one

// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <array>
#include <map>
#include <set>
#include <chrono>
#include <random>
#include <functional>
using namespace std;

mt19937_64 rng((unsigned int)chrono::steady_clock::now().time_since_epoch().count());


// #include <ext/pb_ds/assoc_container.hpp>
// struct splitmix64_hash {
// 	static uint64_t splitmix64(uint64_t x) {
// 		// http://xorshift.di.unimi.it/splitmix64.c
// 		x += 0x9e3779b97f4a7c15;
// 		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
// 		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
// 		return x ^ (x >> 31);
// 	}

// 	size_t operator()(uint64_t x) const {
// 		static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
// 		return splitmix64(x + FIXED_RANDOM);
// 	}
// };

// template <typename K, typename V, typename Hash = splitmix64_hash>
// using HashMap = __gnu_pbds::gp_hash_table<K, V, Hash>;

// template <typename K, typename Hash = splitmix64_hash>
// using HashSet = HashMap<K, __gnu_pbds::null_type, Hash>;



// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template<class T>
// using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// template<class K, class V>
// using ordered_map = tree<K, V, std::less<K>, rb_tree_tag, tree_order_statistics_node_update>;

// debug starts
template<typename T, typename = void> struct is_iterable : false_type {};
template<typename T> struct is_iterable<T, void_t<decltype(begin(declval<T>())), decltype(end(declval<T>()))>> : true_type {};
template<typename T> typename enable_if<is_iterable<T>::value && !is_same<T, string>::value, ostream&>::type operator<<(ostream& cout, T const& v);
template<typename A, typename B> ostream& operator<<(ostream& cout, pair<A, B> const& p) {
	return cout << "(" << p.f << ", " << p.s << ")";
}
template<typename T> typename enable_if<is_iterable<T>::value && !is_same<T, string>::value, ostream&>::type operator<<(ostream& cout, T const& v) {
	cout << "[";
	for (auto it = v.begin(); it != v.end();) {
		cout << *it;
		if (++it != v.end()) cout << ", ";
	}
	return cout << "]";
}
// debug ends

using std::string;
static struct IO {
	char tmp[1 << 10];

	// fast input routines
	char cur;

	//#define nextChar() (cur = _getc_nolock(stdin))
	//#define peekChar() (cur)
	inline char nextChar() {
		return cur = _getc_nolock(stdin);
	}
	inline char peekChar() {
		return cur;
	}

	inline operator bool() {
		return peekChar();
	}
	inline static bool isBlank(char c) {
		return (c < '-' && c);
	}
	inline bool skipBlanks() {
		while (isBlank(nextChar())); return peekChar() != 0;
	}

	inline IO& operator >> (char& c) {
		c = nextChar(); return *this;
	}

	inline IO& operator >> (char* buf) {
		if (skipBlanks()) {
			if (peekChar()) {
				*(buf++) = peekChar();
				while (!isBlank(nextChar())) *(buf++) = peekChar();
			} *(buf++) = 0;
		} return *this;
	}

	inline IO& operator >> (string& s) {
		if (skipBlanks()) {
			s.clear(); s += peekChar();
			while (!isBlank(nextChar())) s += peekChar();
		}
		return *this;
	}

	inline IO& operator >> (double& d) {
		if ((*this) >> tmp) sscanf(tmp, "%lf", &d); return *this;
	}

#define defineInFor(intType) \
	inline IO& operator >>(intType & n) { \
		if (skipBlanks()) { \
			int sign = +1; \
			if (peekChar() == '-') { \
				sign = -1; \
				n = nextChar() - '0'; \
			} else \
				n = peekChar() - '0'; \
			while (!isBlank(nextChar())) { \
				n += n + (n << 3) + peekChar() - 48; \
			} \
			n *= sign; \
		} \
		return *this; \
	}

	defineInFor(int)
		defineInFor(unsigned int)
		defineInFor(long long)

		// fast output routines

	//#define putChar(c) _putc_nolock((c), stdout)
		inline void putChar(char c) {
		_putc_nolock(c, stdout);
	}
	inline IO& operator << (char c) {
		putChar(c); return *this;
	}
	inline IO& operator << (const char* s) {
		while (*s) putChar(*s++); return *this;
	}

	inline IO& operator << (const string& s) {
		for (int i = 0; i < (int)s.size(); ++i) putChar(s[i]); return *this;
	}

	char* toString(double d) {
		sprintf(tmp, "%lf%c", d, '\0'); return tmp;
	}
	inline IO& operator << (double d) {
		return (*this) << toString(d);
	}


#define defineOutFor(intType) \
	inline char * toString(intType n) { \
		char * p = (tmp + 30); \
		if (n) { \
			bool isNeg = 0; \
			if (n < 0) isNeg = 1, n = -n; \
			while (n) \
				*--p = (n % 10) + '0', n /= 10; \
			if (isNeg) *--p = '-'; \
		} else *--p = '0'; \
		return p; \
	} \
	inline IO& operator << (intType n) { return (*this) << toString(n); }

	defineOutFor(int)
		defineOutFor(long long)

#define endl ('\n')
#define cout __io__
#define cin __io__
#define int int64_t
} __io__;

constexpr long long inf = 1e18;
constexpr int mod = 998244353;
// constexpr int mod = 1e9 + 7;


void solve() {
	
}

signed main() {
	auto begin = std::chrono::high_resolution_clock::now();
	ios::sync_with_stdio(false);

	int t = 1;
	// cin >> t;
	while (t--) {
		solve();
	}

	auto end = std::chrono::high_resolution_clock::now();
	auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
#ifndef ONLINE_JUDGE
	cout << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
#endif
	return 0;
}

#if !__INCLUDE_LEVEL__
#include __FILE__
int main() {
    int n; in(n);
    vector<string> mat(n); in(mat);
    vector<vector<int> > dp(n, vector<int>(n, inf));
    Rep(i, n)dp[i][i] = 0;

    vector<vector<vector<int>>> in(n, vector<vector<int>>(26));
    vector<vector<vector<int>>> out(n, vector<vector<int>>(26));

    for (int u = 0; u < n; u++) {
        for (int v = 0; v < n; v++) {
            char c = mat[u][v];
            if (c == '-') continue;
            int letter = c - 'a';
            out[u][letter].push_back(v);
            in[v][letter].push_back(u);
            dp[u][v] = min(dp[u][v], 1);
        }
    }

    queue<tuple<int, int, int>> q;
    for (int u = 0; u < n; u++) {
        q.push({u, u, dp[u][u]});
    }
    for (int u = 0; u < n; u++) {
        for (int v = 0; v < n; v++) {
            if (u != v && dp[u][v] == 1) {
                q.push({u, v, 1});
            }
        }
    }

    while (!q.empty()) {
        int x, y, d;
        tie(x, y, d) = q.front();
        q.pop();
        if (d != dp[x][y]) continue;
        for (int a = 0; a < 26; a++) {
            for (int s : in[x][a]) {
                for (int t : out[y][a]) {
                    if (dp[s][t] > d + 2) {
                        dp[s][t] = d + 2;
                        q.push({s, t, dp[s][t]});
                    }
                }
            }
        }
    }

    for (int u = 0; u < n; u++) {
        for (int v = 0; v < n; v++) {
            cout << (dp[u][v] == inf ? -1 : dp[u][v]);
            if (v + 1 < n) cout << " ";
        }
        cout << "\n";
    }
}
#else
#include <iostream>
#if __has_include(<atcoder/all>)
#include <atcoder/all>
using namespace atcoder;
#endif
#define rep(i, j, n) for (long long i = j; i < (long long)(n); i++)
#define REP(i, j, n) for (long long i = j; i <= (long long)(n); i++)
#define Rep(i, n) rep(i, 0, n)
#define RREP(i, n) REP(i, 0, n)
#define krep(i, j, n) for (long long i = j; i > (long long)(n); i--)
#define KREP(i, j, n) for (long long i = j; i >= (long long)(n); i--)
#define Krep(i, n) krep(i, n, 0)
#define KRep(i, n) KREP(i, n, 0)
#define wh while
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define vec vector<int>
#define vll vector<long long>
#define str string
#define vst vector<str>
#define el '\n'
#define spa ' '
#define Yes cout << "Yes" << el
#define No cout << "No" << el
#define YES cout << "YES" << el
#define NO cout << "NO" << el
#define cn continue
#define br cout << endl
#define rt1 return 1
#define rt0 return 0
#include <cassert>
#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>

//  ~^ んぁ〜
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int inf = 1073741823;
const int MOD109 = 1e9 + 7;
const int MOD998 = 998244353;
const ll infl = 1LL << 60;
const string abc = "abcdefghijklmnopqrstuvwxyz";
const string ABC = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const string a123 = "123456789";
template <typename T1, typename T2>
inline bool chmax(T1& a, T2 b) {
    bool compare = (a < b);
    if (compare) a = b;
    return compare;
}
template <typename T1, typename T2>
inline bool chmin(T1& a, T2 b) {
    bool compare = (a > b);
    if (compare) a = b;
    return compare;
}

ostream& operator<<(ostream& dest, __int128_t value) {
    ostream::sentry s(dest);
    if (s) {
        __uint128_t tmp = value < 0 ? -value : value;
        char buffer[128];
        char* d = end(buffer);
        do {
            --d;
            *d = "0123456789"[tmp % 10];
            tmp /= 10;
        } while (tmp != 0);
        if (value < 0) {
            --d;
            *d = '-';
        }
        int len = end(buffer) - d;
        if (dest.rdbuf()->sputn(d, len) != len) {
            dest.setstate(ios_base::badbit);
        }
    }
    return dest;
}

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    for (int i = 0; i < (int)v.size(); i++) {
        os << v[i] << (i + 1 != (int)v.size() ? " " : "");
    }
    return os;
}

template <typename T>
ostream& operator<<(ostream& os, const set<T>& set_var) {
    for (auto itr = set_var.begin(); itr != set_var.end(); itr++) {
        os << *itr;
        ++itr;
        if (itr != set_var.end()) os << " ";
        itr--;
    }
    return os;
}

template <typename T, typename U>
ostream& operator<<(ostream& os, const map<T, U>& map_var) {
    for (auto itr = map_var.begin(); itr != map_var.end(); itr++) {
        os << itr->first << " -> " << itr->second << "\n";
    }
    return os;
}

template <typename T, typename U>
ostream& operator<<(ostream& os, const pair<T, U>& pair_var) {
    os << "(" << pair_var.first << ", " << pair_var.second << ")";
    return os;
}

void out() {
    cout << '\n';
}
template <class T, class... Ts>
void out(const T& a, const Ts &...b) {
    cout << a;
    (cout << ... << (cout << ' ', b));
    cout << '\n';
}

template <typename T>
istream& operator>>(istream& is, vector<T>& v) {
    for (T& in : v) is >> in;
    return is;
}

inline void in(void) {
    return;
}
template <typename First, typename... Rest>
void in(First& first, Rest &...rest) {
    cin >> first;
    in(rest...);
    return;
}

string substrback(string s, size_t p, size_t l) {
    // s=文字列　p＝後ろから数えて何文字目　//l=pから何文字目
    const size_t strl = s.length();
    return s.substr(strl - p, l);
}
// pair型のfirstで比較
bool comparePairs(const pair<ll, ll>& a, const pair<ll, ll>& b) {
    // pairのfirstで比較し、同じであればsecondで比較する
    if (a.first != b.first) return a.first < b.first;
    return a.second < b.second;
}
// pair型のセカンドで比較
bool comparePairs2(const pair<ll, ll>& a, const pair<ll, ll>& b) {
    // pairのseondで比較し、同じであればfirstで比較する
    if (a.second != b.second) return a.second < b.second;
    return a.first < b.first;
}
// nの階乗
ull facto(ll n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    else {
        return n * facto(n - 1);
    }
}
// nまでのΣ
ll sigma(ll n) {
    ull sum = 0;
    sum = n * (n + 1) / 2;
    return sum;
}
struct D3 {
    int A, B, index;
};
struct d3 {
    ll a, b, c;
};
// 回文チェック
bool isPalindrome(const string& stri) {
    if (stri.length() <= 1) return true;
    string reversedStr = stri;
    reverse(reversedStr.begin(), reversedStr.end());
    return stri == reversedStr;
}
bool compare(const D3& a, const D3& b) {
    if (a.A == b.A) {
        return a.B < b.B;  // Aが同じ場合、Bで昇順にソート
    }
    return a.A > b.A;  // Aで降順にソート
}
// 切り上げ
ll floor(ll x, ll m) {
    ll r = (x % m + m) % m;
    return (x - r) / m;
}
// 累乗
ll power(ll i, int j) {
    if (!j) return 1;
    if (j == 1) return i;

    ll ans = i;
    for (int u = 0; u < j - 1; u++) ans *= i;
    return ans;
}
bool isPrime(ll n) {
    if (n == 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;

    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}
struct point {
    double x, y;
};

struct segment {
    point p1, p2;
};

long long isqrt(long long x) {
    long long r = (long long)floor(sqrtl((long double)x));
    while ((r + 1) * (long long)(r + 1) <= x) r++;
    while (r * r > x) r--;
    return r;
}
double distance(const point& a, const point& b) {
    return hypot(a.x - b.x, a.y - b.y);
}

double printsegment(const point& a, const point& b, int T) {
    return distance(a, b) / T;
}

double movelaser(const point& a, const point& b, int S) {
    return distance(a, b) / S;
}
int64_t powmod(int64_t K, int64_t mod) {
    int64_t result = 1;
    int64_t base = 2 % mod;
    while (K > 0) {
        if (K & 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        K >>= 1;
    }
    return result;
}

template <class T>
class BitVector {
private:
    unsigned n, cur, p;
    vector<unsigned> acc, bit;
    vector<T> srsum;

public:
    BitVector() {}

    BitVector(vector<bool>& b) {
        cur = 0;
        n = b.size();
        acc.resize((n >> 5) + 2, 0);
        bit.resize((n >> 5) + 2, 0);
        srsum.resize(n + 1, 0);
        for (int i = 0; i < n; i++) {
            if (!(i & 31)) {
                cur++;
                acc[cur] = acc[cur - 1];
            }
            if (b[i]) {
                acc[cur] += int(b[i]);
                bit[cur - 1] |= (1U << (32 - (i & 31) - 1));
            }
        }
    }

    inline void srsum_set(const vector<T>& v) {
        for (int i = 0; i < n; i++) {
            srsum[i + 1] = srsum[i] + v[i];
        }
    }

    inline unsigned rank(unsigned k) {
        if (!(k & 31)) return acc[k >> 5];
        return acc[k >> 5] + __builtin_popcount(bit[k >> 5] >> (32 - (k & 31)));
    }

    inline T rank_srsum(unsigned k) {
        return srsum[k];
    }

    inline bool access(unsigned k) {
        return (rank(k + 1) - rank(k)) == 1;
    }
};

template <class T>
class WaveletMatrix {
private:
    unsigned n;
    unsigned bitsize;
    vector<BitVector<T> > b;
    vector<unsigned> zero;
    vector<int> stInd;
    vector<unsigned> compressed;
    vector<T> cmp;
    vector<long long> sum;
    T MI, MA;

    // v[l,r) の中で値がk未満の総和を返す
    long long rank_sum(unsigned l, unsigned r, unsigned k) {
        long long less_sum = 0;
        for (unsigned i = 0; i < bitsize and l < r; i++) {
            const unsigned rank1_l = b[i].rank(l);
            const unsigned rank1_r = b[i].rank(r);
            const unsigned rank0_l = l - rank1_l;
            const unsigned rank0_r = r - rank1_r;
            if (k & (1U << (bitsize - i - 1))) {
                less_sum += b[i].rank_srsum(rank0_r) - b[i].rank_srsum(rank0_l);
                l = zero[i] + rank1_l;
                r = zero[i] + rank1_r;
            }
            else {
                l = rank0_l;
                r = rank0_r;
            }
        }
        return less_sum;
    }

    // v[l,r) の中で値がk未満の個数を返す
    unsigned rank_less(unsigned l, unsigned r, T k) {
        unsigned less = 0;
        for (unsigned i = 0; i < bitsize and l < r; i++) {
            const unsigned rank1_l = b[i].rank(l);
            const unsigned rank1_r = b[i].rank(r);
            const unsigned rank0_l = l - rank1_l;
            const unsigned rank0_r = r - rank1_r;
            if (k & (1U << (bitsize - i - 1))) {
                less += (rank0_r - rank0_l);
                l = zero[i] + rank1_l;
                r = zero[i] + rank1_r;
            }
            else {
                l = rank0_l;
                r = rank0_r;
            }
        }
        return less;
    }

    // v[l,r) の中で値がk未満の個数と総和を返す
    pair<long long, long long> rank_less_sum(unsigned l, unsigned r, T k) {
        long long less = 0;
        long long less_sum = 0;
        for (unsigned i = 0; i < bitsize and l < r; i++) {
            const unsigned rank1_l = b[i].rank(l);
            const unsigned rank1_r = b[i].rank(r);
            const unsigned rank0_l = l - rank1_l;
            const unsigned rank0_r = r - rank1_r;
            if (k & (1U << (bitsize - i - 1))) {
                less += (rank0_r - rank0_l);
                less_sum += b[i].rank_srsum(rank0_r) - b[i].rank_srsum(rank0_l);
                l = zero[i] + rank1_l;
                r = zero[i] + rank1_r;
            }
            else {
                l = rank0_l;
                r = rank0_r;
            }
        }
        return {less, less_sum};
    }

    inline unsigned compress(const T& x) {
        return lower_bound(cmp.begin(), cmp.end(), x) - begin(cmp);
    }

public:
    // コンストラクタ
    WaveletMatrix() {}
    WaveletMatrix(vector<T> v) {
        MI = numeric_limits<T>::min();
        MA = numeric_limits<T>::max();
        n = v.size();
        cmp = v;
        sort(cmp.begin(), cmp.end());
        cmp.erase(unique(cmp.begin(), cmp.end()), cmp.end());
        compressed.resize(n);
        sum.resize(n + 1);
        vector<T> tmp(n);
        vector<unsigned> tmpc(n);
        unsigned size_mx = v.size();
        for (unsigned i = 0; i < n; i++) {
            compressed[i] = distance(cmp.begin(),
                lower_bound(cmp.begin(), cmp.end(), v[i]));
            sum[i + 1] = sum[i] + v[i];
        }
        stInd.resize(cmp.size() + 1, -1);
        bitsize = bit_width(size_mx);
        b.resize(bitsize);
        zero.resize(bitsize, 0);
        vector<bool> bit(n, 0);
        for (unsigned i = 0; i < bitsize; i++) {
            for (unsigned j = 0; j < n; j++) {
                bit[j] = compressed[j] & (1U << (bitsize - i - 1));
                zero[i] += unsigned(!bit[j]);
                tmp[j] = v[j];
                tmpc[j] = compressed[j];
            }
            b[i] = BitVector<T>(bit);
            int cur = 0;
            for (unsigned j = 0; j < n; j++) {
                if (!bit[j]) {
                    v[cur] = tmp[j];
                    compressed[cur] = tmpc[j];
                    cur++;
                }
            }
            for (unsigned j = 0; j < n; j++) {
                if (bit[j]) {
                    v[cur] = tmp[j];
                    compressed[cur] = tmpc[j];
                    cur++;
                }
            }
            b[i].srsum_set(v);
        }

        for (unsigned i = 0; i < n; i++) {
            if (stInd[compressed[i]] == -1) {
                stInd[compressed[i]] = i;
            }
        }
    }

    // get v[k]
    T access(unsigned k) {
        unsigned res = 0;
        unsigned cur = k;
        for (unsigned i = 0; i < bitsize; i++) {
            if (b[i].access(cur)) {
                res |= (1U << (bitsize - i - 1));
                cur = zero[i] + b[i].rank(cur);
            }
            else {
                cur -= b[i].rank(cur);
            }
        }
        return cmp[res];
    }

    // v[0,k) 中でのcの出現回数を返す
    unsigned rank(unsigned k, T c) {
        c = compress(c);
        unsigned cur = k;
        if (stInd[c] == -1) {
            return 0;
        }
        for (unsigned i = 0; i < bitsize; i++) {
            if (c & (1U << (bitsize - i - 1))) {
                cur = zero[i] + b[i].rank(cur);
            }
            else {
                cur -= b[i].rank(cur);
            }
        }
        return cur - stInd[c];
    }

    // v[l,r) の中でk番目(1-origin)に小さい値を返す
    T kth_smallest(unsigned l, unsigned r, unsigned k) {
        unsigned res = 0;
        for (unsigned i = 0; i < bitsize; i++) {
            unsigned num1 = b[i].rank(r) - b[i].rank(l);
            unsigned num0 = r - l - num1;
            if (num0 < k) {
                res |= (1ULL << (bitsize - i - 1));
                l = zero[i] + b[i].rank(l);
                r = zero[i] + b[i].rank(r);
                k -= num0;
            }
            else {
                l -= b[i].rank(l);
                r -= b[i].rank(r);
            }
        }
        return cmp[res];
    }

    // v[l,r) の中でk番目(1-origin)に大きい値を返す
    T kth_largest(unsigned l, unsigned r, unsigned k) {
        return kth_smallest(l, r, r - l - k + 1);
    }

    // v[l,r]を昇順ソートした時の先頭k個の総和を返す
    long long kth_ascending_sum(unsigned l, unsigned r, unsigned k) {
        long long res = 0;
        unsigned val = 0;
        for (unsigned i = 0; i < bitsize; i++) {
            const unsigned rank1_l = b[i].rank(l);
            const unsigned rank1_r = b[i].rank(r);
            const unsigned rank0_l = l - rank1_l;
            const unsigned rank0_r = r - rank1_r;
            const unsigned num1 = rank1_r - rank1_l;
            const unsigned num0 = rank0_r - rank0_l;
            if (num0 < k) {
                val |= (1ULL << (bitsize - i - 1));
                res += b[i].rank_srsum(rank0_r) - b[i].rank_srsum(rank0_l);
                l = zero[i] + rank1_l;
                r = zero[i] + rank1_r;
                k -= num0;
            }
            else {
                l = rank0_l;
                r = rank0_r;
            }
        }
        res += int64_t(cmp[val]) * (k);
        return res;
    }

    // v[l,r]を降順ソートした時の先頭k個の総和を返す
    long long kth_descending_sum(unsigned l, unsigned r, unsigned k) {
        return range_sum(l, r) - kth_ascending_sum(l, r, r - l - k);
    }

    // v[l,r) の中で[mink,maxk)に入る値の個数を返す
    unsigned range_freq(unsigned l, unsigned r, T mink, T maxk) {
        mink = compress(mink);
        maxk = compress(maxk);
        if (mink == 0) {
            return rank_less(l, r, maxk);
        }
        return rank_less(l, r, maxk) - rank_less(l, r, mink);
    }

    // v[l,r) の総和を返す
    long long range_sum(unsigned l, unsigned r) {
        return sum[r] - sum[l];
    }

    // v[l,r) の中で[mink,maxk)に入る値の総和を返す
    long long range_sum(unsigned l, unsigned r, T mink, T maxk) {
        mink = compress(mink);
        maxk = compress(maxk);
        return rank_sum(l, r, maxk) - rank_sum(l, r, mink);
    }

    // v[l,r) の中で ∑|v[i]-d| を計算して返す
    long long range_abs(unsigned l, unsigned r, T d) {
        T dnum = rank(r, d) - rank(l, d);
        T dsum = d * dnum;
        T asum = range_sum(l, r);
        auto p = rank_less_sum(l, r, compress(d));
        T less = p.first;
        T less_sum = p.second;
        T more = r - l - dnum - less;
        T more_sum = asum - dsum - less_sum;
        return d * less + more_sum - less_sum - (d * more);
    }

    // v[l,r)の中でvalを超えない最大の値を返す
    T prev_value(unsigned l, unsigned r, T val) {
        int num = range_freq(l, r, MI, val);
        if (num == 0) {
            return MA;
        }
        else {
            return kth_smallest(l, r, num);
        }
    }

    // v[l,r)の中でval以上の最小の値を返す
    T next_value(unsigned l, unsigned r, T val) {
        int num = range_freq(l, r, MI, val);
        if (num == r - l) {
            return MI;
        }
        else {
            return kth_smallest(l, r, num + 1);
        }
    }
};

// 遅延伝搬反転可能乱択平衡二分探索木
//  -- エフェメラルFHQ Treapのノード (cloneしない) --
static const int MAXN = 200000;
static const int MAXNODE = MAXN + 5;

struct Node {
    int key;  // 値
    unsigned int pri;
    int sz;    // 部分木サイズ
    int l, r;  // 左右の子 (配列index)
} tr[MAXNODE];

int root = 0;     // 1つだけのTreapの根（永続化しない）
int nodeCnt = 0;  // 使ったノード数

inline int nodeSize(int i) {
    return i ? tr[i].sz : 0;
}

inline void pullUp(int i) {
    tr[i].sz = nodeSize(tr[i].l) + nodeSize(tr[i].r) + 1;
}

int newNode(int key) {
    ++nodeCnt;
    tr[nodeCnt].key = key;
    tr[nodeCnt].pri = rand();
    tr[nodeCnt].sz = 1;
    tr[nodeCnt].l = tr[nodeCnt].r = 0;
    return nodeCnt;
}

// merge(l, r): すべてのキー(l) < すべてのキー(r) 前提
int mergeTreap(int l, int r) {
    if (!l || !r) return l ? l : r;
    if (tr[l].pri > tr[r].pri) {
        tr[l].r = mergeTreap(tr[l].r, r);
        pullUp(l);
        return l;
    }
    else {
        tr[r].l = mergeTreap(l, tr[r].l);
        pullUp(r);
        return r;
    }
}

// splitTreapByKey(t, key):
//   left: キー < key
//   right:キー >= key
//   (t は破壊的に分割され、戻り値でleftとrightを得る)
void splitTreapByKey(int t, int key, int& l, int& r) {
    if (!t) {
        l = r = 0;
        return;
    }
    if (tr[t].key < key) {
        l = t;
        splitTreapByKey(tr[t].r, key, tr[l].r, r);
        pullUp(l);
    }
    else {
        r = t;
        splitTreapByKey(tr[t].l, key, l, tr[r].l);
        pullUp(r);
    }
}

// getMinIndex: 部分木中の最小要素をもつノードのindex
int getMinIndex(int t) {
    while (tr[t].l) t = tr[t].l;
    return t;
}

// removeMin(t): tの最小要素ノードを削除して新根を返す
int removeMin(int t) {
    if (!t) return 0;
    if (!tr[t].l) {
        // 自分が最小
        return tr[t].r;
    }
    tr[t].l = removeMin(tr[t].l);
    pullUp(t);
    return t;
}

int insertValue(int root, int x) {
    int l, r;
    splitTreapByKey(root, x, l, r);
    // rの最小が >= x なら削除
    if (r) {
        int m = getMinIndex(r);
        if (tr[m].key >= x) {
            r = removeMin(r);
        }
    }
    int nd = newNode(x);
    return mergeTreap(mergeTreap(l, nd), r);
}

// countLE(root, X): "キー <= X" の個数
int countLE(int& root, int X) {
    int l, r;
    splitTreapByKey(root, X + 1, l, r);
    int ans = nodeSize(l);
    // 元に戻す
    root = mergeTreap(l, r);
    return ans;
}

struct Query {
    int R;
    long long X;
    int idx;
};
#endif

#include <bits/stdc++.h>
using namespace std;

class BigInt10 : public std::vector<int> {
    static inline constexpr int g = 11, M = 754974721; // 1 +  2^24 * 45
	static inline std::vector<int> rev, roots{0, 1};
	static int powMod(int x, int n) {
		int r(1);
		while (n) {
			if (n&1) r = 1LL * r * x % M;
			n >>= 1; x = 1LL * x * x % M;
		}
		return r;
	}
	void dft() {
		int n = size();
		if ((int)rev.size() != n) {
			int k = __builtin_ctz(n) - 1;
			rev.resize(n);
			for (int i = 0; i < n; ++i) {
				rev[i] = rev[i >> 1] >> 1 | (i & 1) << k;
			}
		}
		if ((int)roots.size() < n) {
			int k = __builtin_ctz(roots.size());
			roots.resize(n);
			while ((1 << k) < n) {
				int e = powMod(g, (M - 1) >> (k + 1));
				for (int i = 1 << (k - 1); i < (1 << k); ++i) {
					roots[2 * i] = roots[i];
					roots[2 * i + 1] = 1LL * roots[i] * e % M;
				}
				++k;
			}
		}
		for (int i = 0; i < n; ++i) if (rev[i] < i) {
			std::swap((*this)[i], (*this)[rev[i]]);
		}
		for (int k = 1; k < n; k *= 2) {
			for (int i = 0; i < n; i += 2 * k) {
				for (int j = 0; j < k; ++j) {
					int u = (*this)[i + j];
					int v = 1LL * (*this)[i + j + k] * roots[k + j] % M;
					int x = u + v, y = u - v;
					if (x >= M) x -= M;
					if (y < 0) y += M;
					(*this)[i + j] = x;
					(*this)[i + j + k] = y;
				}
			}
		}
	}
	void idft() {
		int n = size();
		std::reverse(begin() + 1, end());
		dft();
		int inv = powMod(n, M - 2);
		for (int i = 0; i < n; ++i) {
			(*this)[i] = 1LL * (*this)[i] * inv % M;
		}
	}
public:
	// The above are used for NTT
	bool ngt;
	using std::vector<int>::vector; // this will not init ngt
	BigInt10(const std::vector<int> &a, bool _ngt) : std::vector<int>::vector{a}, ngt(_ngt) {}
	BigInt10() { ngt = false;}
	BigInt10(const int &x) {
		ngt = (x < 0);
		if (x == 0) return;
		emplace_back(abs(x));
		standard();
	}
	BigInt10(const long long &x) {
		ngt = (x < 0);
		if (x == 0) return;
		auto now = abs(x);
		while (now) {
			auto tmp = now / 10;
			emplace_back(now - tmp * 10);
			now = tmp;
		}
	}
	// BigInt10(const std::vector<int> &a) : std::vector<int>{a} { ngt = true;}
	// 当前仅接受 0-9 序列
	BigInt10(const std::string &s) {
		ngt = false;
		int i = 0, n = s.size();
		while (i < n && (s[i] < '0' || s[i] > '9')) {
			if (s[i] == '-') ngt = true;
			++i;
		}
		while (i < n && s[i] >= '0' && s[i] <= '9') {
			emplace_back(s[i] - '0');
			++i;
		}
		reverse();
	}
	std::string toString() const {
		if (empty()) return "0";
		std::string s;
		for (auto x : (*this)) s += char(x + '0');
		if (ngt) s += '-';
		std::reverse(s.begin(), s.end());
		return s;
	}
	friend std::istream &operator>>(std::istream &in, BigInt10 &A) {
		std::string s;
		in >> s;
		A = BigInt10(s);
		return in;
	}
	friend std::ostream &operator<<(std::ostream &out, const BigInt10 &A) {
		out << A.toString();
		return out;
	}
	// postive zero is the same as negetive zero
	void opposite() {
		if (!empty()) ngt = !ngt;
	}
	void negtive() {
		if (!empty()) ngt = true;
	}
	void positive() {
		ngt = false;
	}
	// left and right shift
	BigInt10 mulXn(int n) const {
		auto A = *this;
		if (!A.empty()) A.insert(A.begin(), n, 0);
		return A;
	}
	BigInt10 modXn(int n) const {
		if (n >= (int)size()) return *this;
		return BigInt10({begin(), begin() + n}, ngt);
	}
	BigInt10 divXn(int n) const {
		if ((int)size() <= n) return BigInt10();
		return BigInt10({begin() + n, end()}, ngt);
	}
	bool operator<(const BigInt10 &B) const {
		if (ngt) {
			if (B.ngt) return absCompare(B, *this);
			return true;
		}
		if (B.ngt) return false;
		return absCompare(*this, B);
	}
	bool operator<=(const BigInt10 &B) const {
		if (ngt) {
			if (B.ngt) return absCompareEqual(B, *this);
			return true;
		}
		if (B.ngt) return false;
		return absCompareEqual(*this, B);
	}
	BigInt10 &operator+=(const BigInt10 &B) {
		bool flag = ngt;
		if (ngt == B.ngt) {
			*this = add(*this, B);
		} else {
			if (absCompare(*this, B)) {
				flag = B.ngt;
				*this = sub(B, *this);
			} else {
				*this = sub(*this, B);
			}
		}
		this->ngt = flag;
		return (*this);
	}
	BigInt10 &operator-=(const BigInt10 &B) {
		bool flag = ngt;
		if (ngt == B.ngt) {
			if (absCompare(*this, B)) {
				flag = !ngt;
				*this = sub(B, *this);
			} else {
				*this = sub(*this, B);
			}
		} else {
			*this = add(*this, B);
		}
		this->ngt = flag;
		return (*this);
	}
	BigInt10 operator+(const BigInt10 &B) const {
		return BigInt10(*this) += B;
	}
	BigInt10 operator-(const BigInt10 &B) const {
		return BigInt10(*this) -= B;
	}
	BigInt10 &operator*=(BigInt10 rhs) {
		return *this = mul(*this, rhs);
	}
	BigInt10 operator*(const BigInt10 &rhs) const {
		return mul(*this, rhs);
	}
	BigInt10 &operator/=(BigInt10 rhs) {
		return *this = div(*this, rhs);
	}
	BigInt10 operator/(BigInt10 rhs) const {
		return div(*this, rhs);
	}
	BigInt10 &operator%=(BigInt10 rhs) {
		return (*this) -= (*this) / rhs * rhs; 
	}
	BigInt10 operator%(BigInt10 rhs) const {
		return BigInt10(*this) %= rhs;
	}
	BigInt10 &operator++() {
		if (empty()) return (*this) = BigInt10(1);
		if (ngt) prefixDecrement();
		else prefixIncrement();
		return (*this);
	}
	BigInt10 &operator--() {
		if (empty()) return (*this) = BigInt10(-1);
		if (ngt) prefixIncrement();
		else prefixDecrement();
		return (*this);
	}
private:
	void prefixIncrement() {
		int n = this->size(), i = 0;
		while (i < n && (*this)[i] == 9) ++i;
		if (i == this->size()) emplace_back(1);
		else ++((*this)[i]);
		std::fill(begin(), begin() + i, 0);
	}
	void prefixDecrement() {
		int n = this->size(), i = 0;
		while (i < n && (*this)[i] == 0) ++i;
		--((*this)[i]);
		std::fill(begin(), begin() + i, 9);
		if (back() == 0) pop_back();
	}
	void removeLeadingZero() {
		while (!empty() && back() == 0) pop_back();
		if (empty()) ngt = false;
	}
	void standard() {
		int now = 0; // claim that now < 2M 
		for (auto &x : *this) {
			now += x;
			auto tmp = now / 10;
			x = now - tmp * 10;
			now = tmp;
		}
		while (now) {
			auto tmp = now / 10;
			emplace_back(now - tmp * 10);
			now = tmp;
		}
		removeLeadingZero();
	}
	void reverse() {
		std::reverse(begin(), end());
		removeLeadingZero();
	}
	friend bool absCompare(const BigInt10 &A, const BigInt10 &B) {
		if (A.size() < B.size()) return true;
		if (A.size() > B.size()) return false;
		for (int i = A.size() - 1; i >= 0; --i) {
			if (A[i] != B[i]) return A[i] < B[i];
		}
		return false;
	}
	friend BigInt10 abs(const BigInt10 &A) {
		auto B = A;
		B.ngt = false;
		return B;
	}
	friend bool absCompareEqual(const BigInt10 &A, const BigInt10 &B) {
		if (A.size() < B.size()) return true;
		if (A.size() > B.size()) return false;
		for (int i = A.size() - 1; i >= 0; --i) {
			if (A[i] != B[i]) return A[i] < B[i];
		}
		return true;
	}
	// unsigned add
	friend BigInt10 add(const BigInt10 &A, const BigInt10 &B) {
		BigInt10 C(A);
		C.resize(std::max(A.size(), B.size()));
		for (int i = 0, nb = B.size(); i < nb; ++i) C[i] += B[i];
		C.standard();
		return C;
	}
	// unsigned sub: assume A >= B
	friend BigInt10 sub(const BigInt10 &A, const BigInt10 &B) {
		BigInt10 C(A);
		for (int i = C.size() - 1; i > 0; --i) {
			--C[i];
			C[i - 1] += 10;
		}
		for (int i = 0, nb = B.size(); i < nb; ++i) C[i] -= B[i];
		C.standard();
		return C;
	}
	friend BigInt10 mul(BigInt10 A, BigInt10 B) {
		if (A.empty() || B.empty()) return BigInt10(0);
		bool flag = A.ngt ^ B.ngt;
		int n = A.size(), m = B.size(), tot = std::max(1, n + m - 1);
		int sz = 1 << std::__lg(tot * 2 - 1);
		A.resize(sz);
		B.resize(sz);
		A.dft();
		B.dft();
		for (int i = 0; i < sz; ++i) {
			A[i] = 1LL * A[i] * B[i] % M;
		}
		A.idft();
		A.ngt = flag;
		A.standard();
		return A;
	}
	friend BigInt10 inv(const BigInt10 &A) {
		int n = A.size();
		// if (n == 1) return BigInt10(100 / A[0]); // this case will be deal in div
		if (n == 2) return BigInt10(10000 / (A[0] + A[1] * 10));
		int k = n / 2 + 1;
		BigInt10 B = inv(BigInt10(A.end() - k, A.end()));
		B = sub(add(B, B).mulXn(n - k), mul(mul(A, B), B).divXn(2 * k));
		return B;
	}
	friend BigInt10 div(BigInt10 A, BigInt10 B) {
		assert(!B.empty()); // div by zero
		bool flag = A.ngt ^ B.ngt;
		if (absCompare(A, B)) return BigInt10(0);
		int n = A.size(), m = B.size();
		if (n > 2 * m) {
			A = A.mulXn(n - m * 2);
			B = B.mulXn(n - m * 2);
			m = n - m;
			n = m * 2;
		}
		if (B.size() == 1) return (A[0] + (A.size() == 1 ? 0 : A[1] * 10)) / B[0];
		BigInt10 D = inv(B), ans(0), DB = mul(D, B);
		if (DB.size() >= 2 * m) { // actually at most once
			DB -= B;
			if (D[0] == 0) D = sub(D, 1);
			else --D[0];
		}
		while (absCompareEqual(B, A)) {
			auto C = mul(A, D).divXn(2 * m);
			if (C.empty()) break;
			ans = add(ans, C);
			A = sub(A, mul(B, C));
		}
		while (absCompareEqual(B, A)) A = sub(A, B), ++ans[0];
		ans.ngt = flag;
		ans.standard();
		return ans;
	}
};

signed main() {
    string a, b;
    cin >> a >> b;
    BigInt10 A(a), B(b);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
const int N = 1e7 + 5;
const int mod = 1e9 + 7;

vector<int> smallest_factor;
vector<bool> prime;
vector<int> primes;

void sieve(int maximum) {
    maximum = max(maximum, 1);
    smallest_factor.assign(maximum + 1, 0);
    prime.assign(maximum + 1, true);
    prime[0] = prime[1] = false;
    primes = {};

    for (int p = 2; p <= maximum; p++)
        if (prime[p]) {
            smallest_factor[p] = p;
            primes.push_back(p);

            for (int64_t i = int64_t(p) * p; i <= maximum; i += p)
                if (prime[i]) {
                    prime[i] = false;
                    smallest_factor[i] = p;
                }
        }
}

// Prime factorizes n in worst case O(sqrt n / log n). Requires having run `sieve` up to at least sqrt(n).
// If we've run `sieve` up to at least n, takes O(log n) time.
vector<pair<int64_t, int>> prime_factorize(int64_t n) {
    int64_t sieve_max = int64_t(smallest_factor.size()) - 1;
    assert(1 <= n && n <= sieve_max * sieve_max);
    vector<pair<int64_t, int>> result;

    if (n <= sieve_max) {
        while (n != 1) {
            int64_t p = smallest_factor[n];
            int exponent = 0;

            do {
                n /= p;
                exponent++;
            } while (n % p == 0);

            result.emplace_back(p, exponent);
        }

        return result;
    }

    for (int64_t p : primes) {
        if (p * p > n)
            break;

        if (n % p == 0) {
            result.emplace_back(p, 0);

            do {
                n /= p;
                result.back().second++;
            } while (n % p == 0);
        }
    }

    if (n > 1)
        result.emplace_back(n, 1);

    return result;
}

const int N = 1000100;
vector<bool> isprime;
vector<int> primes;
int seivedone;
vector<int> maxprime, minprime;

void seive() {
    if (seivedone) return;
    isprime.assign(N, true);
    maxprime.assign(N, 0);
    minprime.assign(N, 0);
    isprime[0] = isprime[1] = 0;
    for (int i = 2; i < N; i++) {
        if (isprime[i]) {
            minprime[i] = maxprime[i] = i;
            for (int j = 2 * i; j < N; j += i) {
                isprime[j] = 0;
                maxprime[j] = i;
                if (minprime[j] == 0) minprime[j] = i;
            }
            primes.push_back(i);
        }
    }
    seivedone = 1;
}

vector<int> primefactors(int n) {
    seive();
    vector<int> res;
    for (auto& p : primes) {
        if (p * p > n) break;
        if (n % p == 0) {
            res.push_back(p);
            while (n % p == 0) n /= p;
        }
    }
    if (n != 1) res.push_back(n);
    return res;
}

vector<int> primes;
void seive(int n) {
    vector<bool> isprime(n + 1, true);
    for (int i = 2; i <= n; i++) {
        if (isprime[i]) p.push_back(i);
        for (int j = 2 * i; j <= n; j += i) {
            isprime[j] = false;
        }
    }
}

// to find divisors
vector<int> divisors[N];
void computedivisors() {
    for (int i = 2; i < N; i++) {
        for (int j = i; j < N; j += i) {
            divisors[j].push_back(i);
        }
    }
}

inline vector<int> div(int n) {
    vector<int> d;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            d.push_back(i);
            if (n / i != i) {
                d.push_back(n / i);
            }
        }
    }
    sort(d.begin(), d.end());
    return d;
}

inline vector<int> f(int x) {
    vector<int> p;
    int t = x;
    for (auto i : primes) {
        if (i * i > t) break;
        if (x % i == 0) {
            int c = 0;
            while (x % i == 0) {
                c++;
                x /= i;
            }
            p.push_back(c);
        }
    }
    if (isPrime[x]) p.push_back(1);
    return p;
}

int main() {
    seive();

    return 0;
}
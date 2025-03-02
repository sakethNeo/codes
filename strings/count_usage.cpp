#include<bits/stdc++.h>
using namespace std;

#define int long long
const int mod = 1e9 + 7;
const int inf = 1e18;

class Count {
public:
    vector<int> v;
    Count() : v(26, 0) {}
    Count(string& s) : v(26, 0) {
        init(s);
    }
    void init(string& s) {
        for (char c : s) {
            v[c - 'a']++;
        }
    }
    void add(char c) {
        v[c - 'a']++;
    }
    int operator[](char i) const {
        return v[i - 'a'];
    }
    int& operator[](char i) { 
        return v[i - 'a'];
    }
    Count& operator=(const Count& c) {
        if (this != &c) {
            v = c.v;
        }
        return *this;
    }
    Count operator+(const Count& c) const {
        Count nv;
        for (int i = 0; i < 26; i++) {
            nv.v[i] = v[i] + c.v[i];
        }
        return nv;
    }
    Count& operator+=(const Count& c) { 
        for (int i = 0; i < 26; i++) {
            v[i] += c.v[i];
        }
        return *this;
    }
    bool isempty() {
        return (count(v.begin(), v.end(), 0) == 26);
    }
    int size() {
        return accumulate(v.begin(), v.end(), 0);
    }
};

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string in;
	getline(cin, in);
	stringstream s(in);
	int num;
	vector<int> arr;
	while (s >> num) arr.push_back(num);
	for (auto i : arr) cout << i << " ";

	return 0;
}

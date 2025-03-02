#include <bits/stdc++.h>
using namespace std;

vector<int> prefix_function(const string& s) {
    int n = s.size();
    vector<int> pi(n, 0);
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j]) {
            j = pi[j - 1];
        }
        if (s[i] == s[j]) j++;
        pi[i] = j;
    }
    return pi;
}

vector<int> kmp(const string& t, const string& s) {
    string nt = s + "#" + t;
    auto pi = prefix_function(nt);
    int n = nt.size(), m = s.size();
    vector<int> res;
    for (int i = m << 1; i < n; i++) {
        if (pi[i] == m) {
            res.push_back(i - (m << 1));
        }
    }
    return res;
}

int main() {
    string text = "aaabababaaab";
    string pattern = "aaab";

    vector<int> matches = kmp(text, pattern);

    cout << "Pattern found at positions: ";
    for (int pos : matches) {
        cout << pos << " ";
    }
    cout << endl;

    return 0;
}

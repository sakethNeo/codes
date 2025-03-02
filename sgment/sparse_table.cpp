#include <bits/stdc++.h>
using namespace std;


class SparseTable {
private:
    vector<vector<int>> t;
    function<int(int, int)> combine;
public:
    SparseTable(const vector<int>& a, function<int(int, int)> f) : combine(f) {
        initialize(a);
    }
    void initialize(const vector<int>& a) {
        size_t n = a.size();
        int maxLog = bit_width(n);
        t.assign(maxLog, vector<int>(n));
        for (int i = 0; i < n; i++) {
            t[0][i] = a[i];
        }
        for (int lv = 1; lv < maxLog; ++lv) {
            for (int i = 0; i + (1 << lv) <= n; ++i) {
                t[lv][i] = combine(t[lv - 1][i],
                    t[lv - 1][i + (1 << (lv - 1))]);
            }
        }
    }
    int query(int l, int r) {
        int log = bit_width(unsigned(r - l + 1)) - 1;
        return combine(t[log][l],
            t[log][r - (1 << log) + 1]);
    }
};

signed main() {

    vector<int> a = {1, 3, 2, 5, 2, 1, 10, 11};
    SparseTable st(a, [](int x, int y) {
        return min(x, y);
    });
    cout << st.query(2, 7) << "\n";

    return 0;
}

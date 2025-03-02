#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
#include <set>
#include <utility>
#include <iterator>
#include <map>
#define ll long long
#define fin for(i=0;i<n;i++) 
const int mod = 1000000007;
using namespace std;


vector<int> nxtGreaterIdx(const vector<int>& arr) {
    int n = arr.size();
    vector<int> res(n, -1);
    stack<int> s;
    
    for (int i = n - 1; i >= 0; --i) {
        while (!s.empty() && arr[s.top()] <= arr[i]) {
            s.pop();
        }
        if (!s.empty()) {
            res[i] = s.top();
        }
        s.push(i);
    }
    
    return res;
}

vector<int> prvGreaterIdx(const vector<int>& arr) {
    int n = arr.size();
    vector<int> res(n, -1);
    stack<int> s;
    
    for (int i = 0; i < n; ++i) {
        while (!s.empty() && arr[s.top()] <= arr[i]) {
            s.pop();
        }
        if (!s.empty()) {
            res[i] = s.top();
        }
        s.push(i);
    }
    
    return res;
}

int main() {
    long long n;
    cin >> n;
    vector<int> a(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    vector<int> prv = prvGreaterIdx(a);
    vector<int> nxt = nxtGreaterIdx(a);
    vector<int> pre(n, -1);
    vector<int> suf(n, -1);
    
    for (int i = 0; i < n; ++i) {
        pre[i] = i;
        if (i > 0) {
            int j = pre[i - 1];
            if (a[j] > a[i]) {
                pre[i] = j;
            }
        }
    }
    
    for (int i = n - 1; i >= 0; --i) {
        suf[i] = i;
        if (i < n - 1) {
            int j = suf[i + 1];
            if (a[j] > a[i]) {
                suf[i] = j;
            }
        }
    }
    
    int ans = 0;
    for (int i = 1; i < n - 1; ++i) {
        int x = nxt[i], y = prv[i];
        if (prv[i] == -1) {
            y = pre[i - 1];
        }
        if (nxt[i] == -1) {
            x = suf[i + 1];
        }
        ans = max(ans, x - y);
    }
    cout << ans<<endl;
}
#include <bits/stdc++.h>
using namespace std;

class SparseTable{
    private:
        vector<int> a;
        vector<vector<int>> v;
        int mn(int i,int j){
            return (a[v[i][j]]<=a[v[i][j+(1<<(i))]])? v[i][j]:v[i][j+(1<<(i))];
        }
    public:
        SparseTable(vector<int> &inp): a(inp) {
            int n=a.size();
            int k=log2(n)+1;
            v.resize(k,vector<int>(n));
            for(int i=0;i<n;i++) v[0][i]=i;
            for(int i=1;i<k;i++){
                for(int j=0;j+(1<<i)<=n;j++){
                    v[i][j]=mn(i-1,j);
                }
            }
        }
        int query(int l,int r){
            int k=log2(r-l+1);
            return min(a[v[k][l]],a[v[k][l+((1<<k)-1)]]);
        }
};

signed main() {
    vector<int> a={9,3,7,2,4,6,5};
    SparseTable pt(a);
    cout<<pt.query(0,2)<<"\n";
    return 0;
}
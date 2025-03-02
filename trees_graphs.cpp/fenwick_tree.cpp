#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

// lil shit
class Fenwick {
    int n;
    vector<int> t;
public:
    Fenwick(vector<int>& a) : n((int)a.size()) {
        t.resize(n + 1);
        for (int i = 0; i < n; i++) add(i, a[i]);
    }
    Fenwick(int _n) : n(_n) {
        t.resize(n + 1);
    }
    void add(int i, int x) {
        for (i++; i <= n; i += i & -i) {
            t[i] += x;
        }
    }
    int get(int i) {
        int sum = 0;
        for (i++; i; i -= i & -i) {
            sum += t[i];
        }
        return sum;
    }
}


// don't forget that we wrote index++ in functions!!
class FenwickTree {
private:
    vector<int> tree;
 
public:
    FenwickTree(const vector<int>& inputArray) {
        int n = inputArray.size();
        tree.resize(n + 1, 0);

        for (int i = 0; i < n; ++i) {
            update(i, inputArray[i]);
        }
    }

    // function doesn't update the value but it adds the value to the a[index] 
    void update(int index, int value) {
        index++;
        while (index < tree.size()) {
            tree[index] += value;
            index += index & -index;
        }
    }

    int query(int index) const {
        index++;
        int sum = 0;
        while (index > 0) {
            sum += tree[index];
            index -= index & -index;
        }
        return sum;
    }
};

int main() {
    int n=5;
    int k=-n;
    bitset<sizeof(int)*8> bi(k);
    cout<<k<<bi<<"\n";
    vector<int> inputArray = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    FenwickTree fenwickTree(inputArray);

    int queryIndex = 5;
    int result = fenwickTree.query(queryIndex);

    cout << "Sum of first " << queryIndex + 1 << " elements: " << result << endl;

    int updateIndex = 3;
    int updateValue = 10;
    fenwickTree.update(updateIndex, updateValue);

    result = fenwickTree.query(queryIndex);
    cout << "Sum of first " << queryIndex + 1 << " elements after update: " << result << endl;

    return 0;
}

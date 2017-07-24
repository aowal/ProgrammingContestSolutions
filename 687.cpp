#include <iostream>
#include <vector>

using namespace std;

vector<long long> fb(long long n) {
    vector<long long> v;
    v.push_back(2);
    v.push_back(3);
    for (int i = 2; v[i - 1] < n; i++) {
        v.push_back(v[i - 1] + v[i - 2] - 1);
//        cout << v[i] << endl;
    }
    return v;
}


class AlmostFibonacciKnapsack {
public:
    vector<int> getIndices(long x);
};

vector<int> AlmostFibonacciKnapsack::getIndices(long x) {
    vector<long long> t = fb(x);
    t.pop_back();
    vector<int> b;
    if (x == 2)
        return {1};
    else if (x == 3)
        return {2};
    while (x > 1) {
        if (x - t[t.size() - 1] >= 0) {
            x = x - t[t.size() - 1];
            b.push_back(t.size());
            t.pop_back();
        } else
            t.pop_back();
    }

    if (x == 1)
        return {-1};
    else
        return b;
}

int main() {

    long long pp = 86267769395;
    AlmostFibonacciKnapsack af;
    vector<int> kk = af.getIndices(pp);

    for (int i = 0; i < kk.size(); ++i) {
        cout << kk[i] << endl;
    }

    return 0;
}
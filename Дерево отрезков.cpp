#include <bits/stdc++.h>
 
using namespace std;
 
typedef long double ld;
typedef long long ll;
// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
 
#define pb push_back
#define sz(s) int(s.size())
#define all(s) s.begin(), s.end()
#define _GLIBCXX_DEBUG
const ld EPS = 1e-7;
const ll INF_LL = 1e18 + 9;
const int MAX_N = 1e5 + 7;
const int LOG = 22;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 9;
 
// mt19937 r(2329239);
int a[MAX_N];
struct node {
    int mx;
    int ind;
};
struct SegTree {
    vector <node> t;
    void build(int pos, int lx, int rx) {
        if (pos == 0) t.resize(4 * MAX_N);
        if (rx - lx == 1) {
            t[pos] = {a[lx], lx};
        } else {
            int m = (lx + rx) / 2;
            build (pos * 2 + 1, lx, m);
            build (pos * 2 + 2, m, rx);
            if (t[pos * 2 + 1].mx < t[pos * 2 + 2].mx) {
                t[pos] = t[pos * 2 + 2];
            } else {
                t[pos] = t[pos * 2 + 1];
            }
        }
    }
    void set_up(int i, int pos, int lx, int rx, int val) {
        if (rx - lx == 1) {
            t[pos] = {val, lx};
        } else {
            int m = (lx + rx) / 2;
            if (i < m) {
                set_up(i, pos * 2 + 1, lx, m, val);
            } else {
                set_up(i, pos * 2 + 2, m, rx, val);
            }
            if (t[pos * 2 + 1].mx < t[pos * 2 + 2].mx) {
                t[pos] = t[pos * 2 + 2];
            } else {
                t[pos] = t[pos * 2 + 1];
            }
        }
    }
    node get(int l, int r, int pos, int lx, int rx) {
        if (r <= lx || rx <= l) return {-1, -1};
        if (l <= lx && rx <= r) {
            return t[pos];
        }
        int m = (lx + rx) / 2;
        auto s1 = get(l, r, pos * 2 + 1, lx, m);
        auto s2 = get(l, r, pos * 2 + 2, m, rx);
        if (s1.mx < s2.mx) return s2;
        return s1;
    }
};

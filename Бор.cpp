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
 
struct node {
    array <node * , 26> alp;
    bool is_terminal = false;
    node () {
        for (int i = 0; i < 26; i++) {
            alp[i] = nullptr;
        }           
    }
};
node * root = nullptr;
void add_str(string s) {
    node * pos = root;
    for (char c : s) {
        if (pos->alp[c - 'a'] == nullptr) {
            pos -> alp[c - 'a'] = new node ();
        }
        pos = pos -> alp[c - 'a']; 
    }
    pos -> is_terminal = true;
}
bool g[26][26];
vector <int> topsort;
bool used[26];
void dfs(int v) {
    used[v] = true;
    for (int u = 0; u < 26; u++) {
        if (!used[u] && g[v][u]) {
            dfs(u);
        }
    }
    topsort.pb(v);
}
void calc(string s) {
    for (int i = 0; i < 26; i++) {
        used[i] = false;
        for (int j = 0; j < 26; j++) {
            g[i][j] = false;
        }
    }
    topsort.clear();
    node * pos = root;
    for (char c : s) {
        for (int i = 0; i < 26; i++) {
            if (i != c - 'a' && pos -> alp[i] != nullptr) {
                g[i][c - 'a'] = true;
            }
        }
        if (pos -> is_terminal) {
            cout << "nemoguce" << endl;
            return;
        }
        pos = pos -> alp[c - 'a'];

    }
    for (int i = 0; i< 26; i++) {
        if (!used[i]) {
            dfs(i);
        }
    }

    // cout << "@@@" << endl;
    vector <int> ind(26);
    // for (auto p : topsort) {
    //     cout << p << " ";
    // }
    // cout << endl;
    for (int i = 0; i < 26; i++) {
        ind[topsort[i]] = i;
    }
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            if (g[topsort[i]][j] &&  ind[j] > i) {
                cout << "nemoguce" << endl;
                return;
            }
        }
    }
    for (int i = 0; i < 26; i++) {
        cout << char('a' + topsort[i]);
    }
    cout << endl;
}

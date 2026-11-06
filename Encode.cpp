#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <set>
#include <map>
#include <unordered_map>
#include <iomanip>
#include <bitset>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <random>
#include <unordered_set>

typedef long long ll; 
typedef unsigned long long ull; 
typedef long double ld; 
    
using  namespace std;
using namespace __gnu_pbds;


    
#define sz(x) int(x.size())
#define all(v) v.begin(), v.end()
#define mp make_pair
#define pb push_back
#define eb emplace_back
    
    
const int MAX_N = 5e2 + 7;
const int MAX_M = MAX_N * 30;       
const int INF = 1e9 + 9; 
const int WE = 1e3 + 7;
const int LOG = 20;
const int MOD =  998244353;
const int P = 73;
const ull M = ((ull)1 << 31);
const int P1 = 101;
const ll INF_LL = 1e18 + 10; 
// const int M = 1e9 + 9
const int MOVE = 1e4;
const ld EPS = 1e-8;
const int limit = (MAX_N + 63) / 64;

template <typename T> using ordered_multiset = tree<T, null_type,
less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;


int n, m, k,a, b;
ll g[MAX_N][MAX_N];
bool active[MAX_N];
pair <vector <int>, vector <ll>> deikstra(vector <int> start) {
    vector <ll> dist(n, INF_LL);
    vector <int> par(n, n + 1);
    for (int i : start) {
        dist[i] = 0;
    }
    int st = start[0];
    vector <bool> blocked(n + 1, false);
    for (int i = 0; i < n; i++) {
        // cout << i << "@# " << endl;
        int p = -1;
        ll mn = INF_LL;
        for (int j = 0; j < n; j++) {
            if (active[j] && !blocked[j] && mn > dist[j]) {
                mn = dist[j];
                p = j;
            }
            
        }
        if (p == -1) break;
        blocked[p] = true;
        for (int j = 0; j < n; j++) {
            if (g[j][p] != -1 && active[j] && !blocked[j] && dist[j] > mn + g[j][p]) {
                dist[j] = mn + g[j][p];
                if (p == st) {
                    par[j] = j;
                } else {
                    par[j] = par[p];
                }
            }
        }
    }
    return {par, dist};
}
vector <ll> adist;
int main() {
    // freopen("contest.in","r",stdin);
    // freopen("contest.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k >> a >> b;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            g[i][j] = -1;
        }
    }
    vector <int> s;
    for (int i = 0; i < k; i++) {
        int x; cin >> x;
        x--;
        s.pb(x);
    }
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        g[u][v] = w;
        g[v][u] = w;
    }
    
    for (int i = 0; i < n; i++) active[i] = true;
    adist = deikstra(s).second;
    vector <pair <ll, int>> q;
    for (int i = 0; i < n; i++) {
        if (adist[i] != INF_LL) {
            adist[i] *= b;
        }
        q.eb(adist[i], i);
    }
    for (int i = 0; i < n; i++) active[i] = false;
    sort(all(q));
    reverse(all(q));
    ll global_ans = INF_LL;
    for (int i = 0; i < n; i++) {
        auto j = q[i].second;
        active[j] = true;
        auto [par, dists] = deikstra({j});
        ll ans = INF_LL;
        for (int u = 0; u < n; u++) {
            for (int v = 0; v < n; v++) {
                if (g[u][v] == -1) continue;
                if (u != j && v != j) {
                    if (par[u] != par[v]) ans = min(ans, dists[u] + dists[v] + g[u][v]);
                } else {
                    if (u == j && par[v] != v) {
                        ans = min(ans, dists[u] + dists[v] + g[u][v]);
                    } else if(v == j && par[u] != u) {
                        ans = min(ans, dists[u] + dists[v] + g[u][v]);
                    }
                }
            }
        }
        // cout << q[i].first << " " << q[i].second << " " << ans << " "<< endl;
        if (ans != INF_LL)
            global_ans = min(global_ans, ans * a + q[i].first);
    }
    cout << global_ans << endl;
    


    
    



    
    return 0;
}

// 4 3 1
// 1 1 2 1
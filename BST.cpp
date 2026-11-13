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
     
     
const int MAX_N = 3e5 + 7;
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
 
// Тут написано декартово дерево по явному ключу

mt19937 r(239239239);
struct node {
    node * lef = nullptr, * rig = nullptr;
    int sz = 0;
    int x, y = r();
    node (int val) {
        x = val;
        sz = 1;
    }
};
struct BST {
    node * root = nullptr;
};
int get_size(node * root) {
    if (root == nullptr) return 0;
    return root -> sz;
}
void update(node * root) {
    if (root == nullptr) return;
    root -> sz = get_size(root -> lef) + get_size(root -> rig) + 1;
}
node * merge(node * root1, node * root2) {
    if (root1 == nullptr) return root2;
    if (root2 == nullptr) return root1;
    if (root1 -> y < root2 -> y) {
        auto root3 = merge(root2 -> lef, root1);
        root2 -> lef = root3;
        update(root2);
        return root2;
    } else {
        auto root3 = merge(root1 -> rig, root2);
        root1 -> rig = root3;
        update(root1);
        return root1;
    }
}
pair <node *, node *> split(node * root1, int val) {
    if (root1 == nullptr) return {nullptr, nullptr};
    if (root1 -> x >= val) {
        auto [root2, root3] = split(root1 -> lef, val);
        root1 -> lef = root3;
        update(root1);
        return {root2, root1};
    } else {
        auto [root2, root3] = split(root1 -> rig, val);
        root1 -> rig = root2;
        update(root1);
        return {root1, root3};
    }
}
void insert(BST * tr, int val) {
    node * el = new node (val);
    auto [root1, root2] = split(tr->root, val);
    tr->root = merge(merge(root1, el), root2);
}
vector <int> treeel;
void print(node * root) {
    if (root == nullptr) return;
    print(root -> lef);
    // cout << root -> x << " ";
    treeel.pb(root -> x);
    print(root -> rig);
}
void erase(BST * tr, int val) {
    auto [root1, root23] = split(tr->root, val);
    auto [root2, root3] = split(root23, val + 1);
    if (root2 != nullptr) {
        delete root2;
    }
    tr->root = merge(root1, root3);
}
bool contains(BST * tr, int val) {
    auto [root1, root23] = split(tr->root, val);
    auto [root2, root3] = split(root23, val + 1);
    tr->root = merge(merge(root1, root2), root3);
    if (root2 != nullptr) return true;
    return false;
}
bool empty(BST * tr) {
    return tr->root == nullptr;
}

void print_tree(BST * tr) {
    print((*tr).root);
    // cout << endl;
}
int sized(BST * tr) {
    return get_size((*tr).root);
}



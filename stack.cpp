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
    
    
const int MAX_N = 20;
const int MAX_M = MAX_N * 30;       
const int INF = 2e9 + 9; 
const int WE = 1e3 + 7;
const int LOG = 20;
const int MOD2 = 998244353;
const int P2 = 239;
const ull M = ((ull)1 << 31);
const int P1 = 101;
const ll INF_LL = 1e18;
// const int M = 1e9 + 9;
const ld EPS = 1e-8;

template <typename T> using ordered_set = tree<T, null_type,
less<T>, rb_tree_tag, tree_order_statistics_node_update>;


struct Node {
    int value;
    Node * nxt;
};
struct List {
    Node * top;
};
int nan_value = INF;
List * create_a_list() {
    List * new_list = new List();
    new_list -> top = nullptr;
    return new_list;
}
Node * new_cell(int value) {
    Node * new_cell = new Node();
    new_cell->value = value;
    new_cell -> nxt = nullptr;
    return new_cell;
}
void pushback(List* mass, int value) {
    Node * curr = mass -> top;
    if (curr == nullptr) {
        mass -> top = new_cell(value);
        return;
    }
    while (curr -> nxt != nullptr) {
        curr = curr -> nxt;
    }
    curr -> nxt = new_cell(value);
}
bool IsEmpty(List * mass) {
    return mass -> top == nullptr;
}
Node * get_back(List * mass) {
    if (IsEmpty(mass)) {
        return new_cell(nan_value);
    }
    Node * curr = mass -> top;
    while (curr -> nxt != nullptr) {
        curr = curr -> nxt;
    }
    return curr;
}
int get_len(List * mass) {
    Node * curr = mass -> top;
    int len = 0;
    while (curr != nullptr) {
        curr = curr -> nxt;
        len++;
    }
    return len;
}
bool change_element(List * mass, int ind, int value) {
    if (ind < 1 || ind > get_len(mass)) 
        return false;
    Node * curr = mass -> top;
    int len = 1;
    while (len != ind) {
        curr = curr -> nxt;
        len++;
    }
    curr -> value = value;
    return true;
}
bool delete_element(List * mass, int ind) {
    if (ind < 1 || ind > get_len(mass)) 
        return false;
    Node * curr = mass -> top;
    int len = 1;
    while (len < ind - 1) {
        curr = curr -> nxt;
        len++;
    }
    if (get_len(mass) == ind) {
        delete curr -> nxt;
        curr -> nxt = nullptr;
    } else {
        auto nxtnxt = curr -> nxt -> nxt;
        delete curr -> nxt;
        curr -> nxt = nxtnxt;
    }
    return true;
}
int get_value(List * mass, int ind) {
    if (ind < 1 || ind > get_len(mass)) 
        return nan_value;
    Node * curr = mass -> top;
    int len = 1;
    while (len < ind) {
        curr = curr -> nxt;
        len++;
    }
    return curr -> value;
}
int get_first_include (List * mass, int value) {
    if (IsEmpty(mass)) return -1;
    Node * curr = mass -> top;
    int len = 1;
    while (curr != nullptr && curr -> value != value ) {
        curr = curr -> nxt;
    }
    if (curr == nullptr) return -1;
    return len;
}

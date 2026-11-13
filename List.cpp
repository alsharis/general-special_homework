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
    double value;
    Node * nxt;
    Node * pr;
};
struct List {
    Node * top;
};
double nan_value = INF;
List * create_a_list() {
    List * new_list = new List();
    new_list -> top = nullptr;
    return new_list;
}
Node * new_cell(double value) {
    Node * new_cell = new Node();
    new_cell->value = value;
    new_cell -> nxt = nullptr;
    new_cell -> pr = nullptr;
    return new_cell;
}
bool compare(double lef, double rig) {
    return lef <= rig  + EPS;
}
bool IsEmpty(List * mass) {
    return mass -> top == nullptr;
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
void print(List * mass) {
    if (IsEmpty(mass)) return;
    Node * curr = mass -> top;
    while (curr != nullptr) {
        cout << curr -> value << " ";
        curr  = curr -> nxt;
    }
    cout << endl;
    
}


Node * get_element(List * mass, int ind) {
    if (ind < 0 || ind >= get_len(mass)) {
        return nullptr;
    }
    Node * curr = mass -> top;
    int len = 0;
    while (len < ind) {
        curr = curr -> nxt;
        len++;
    }
    return curr;
}
void pushback(List* mass, double value) {
    Node * curr;
    if (get_len(mass) == 0) {
        curr = mass -> top;
        mass -> top = new_cell(value);
    } else {
        curr = get_element(mass, get_len(mass) - 1);
        curr -> nxt = new_cell(value);
        Node * cell = curr -> nxt;
        cell -> pr = curr;
    }
    
}
void pushfront(List* mass, double value) {
    Node * curr = get_element(mass, 0);
    if (curr == nullptr) {
        mass -> top = new_cell(value); 
        return;
    }
    curr -> pr = new_cell(value);
    curr -> pr -> nxt = curr;
    mass -> top = mass -> top -> pr;
}

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
 

int heap[4 * MAX_N];
int a[MAX_N];
int n;
int last = 0;
void sift_up(int pos) {
    if (pos != 0) {
        if (heap[pos] < heap[(pos - 1) / 2]) {
            swap(heap[pos], heap[(pos - 1) / 2]);
            sift_up((pos - 1) / 2);
        }
    }
}
void sift_down(int pos) {
    // cout << pos << " DOW M" << " " << last << " " << heap[pos] << endl;
    if (pos * 2 + 1 < last && pos * 2 + 2 < last) {
        // cout << heap[pos * 2 + 1] << " " << heap[pos * 2 + 2] << endl;
        if (heap[pos] > min (heap[pos * 2 + 1], heap[pos * 2 + 2])) {
            if (heap[pos * 2 + 1] > heap[pos * 2 + 2]) {
                swap(heap[pos], heap[pos * 2 + 2]);
                sift_down(pos * 2 + 2);
            } else {
                swap(heap[pos], heap[pos * 2 + 1]);
                sift_down(pos * 2 + 1);
            }
        }
    } else if (pos * 2 + 1 < last) {
        if (heap[pos] > heap[pos * 2 + 1]) {
            swap(heap[pos], heap[pos * 2 + 1]);
            sift_down(pos * 2 + 1);
        }
    }   
}
void add(int x) {
    heap[last++] = x;
    sift_up(last - 1);
}
void del() {
    swap(heap[0], heap[--last]);
    sift_down(0);
}
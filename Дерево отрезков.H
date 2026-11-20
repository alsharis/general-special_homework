#pragma once

#include <iostream>
#include <utility>
struct node {
    int mx;
    int ind;
    node (int x, int y);
};
struct SegTree {
    std::vector <node> t;
    std::vector <int> a;
    SegTree (std::vector <int> b) ;
    
    void build(int pos, int lx, int rx) {  
    }
    void set_up(int i, int pos, int lx, int rx, int val) {
    }
    node get(int l, int r, int pos, int lx, int rx) {

    }
};
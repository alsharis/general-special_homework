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
#include <LIST.H>

using namespace std;
node::node(int cc) {
    this -> val = cc;
    this -> next = nullptr;
}
bool Circul::contains(int val)  {
            node * el = head;
    do {
        if ((*el).val == val) return true;
        el = (*el).next;
    } while ((*el).next != head);
    return false;
}
void Circul::print() {
    node * el = head;
    do {
        cout << (*el).val << " ";
        el = (*el).next;
    } while (el != head);
    cout << endl;
}
bool Circul::is_empty() {
    return head == nullptr;
}
int Circul::size() {
    return sz;
}
node * Circul::push_back(int val) {
    sz++;
    if (head == nullptr) {
        head = new node {val, nullptr};
        (*head).next = head;
        return head;
    }
    node * el = head;
    while ((*el).next != head) {
        el = (*el).next;
    }
    node * new_el = new node {val, head};
    (*el).next = new_el;
    return new_el;
}
void Circul::push_front(int val) {
    auto el = push_back(val);
    head = el;
}
void Circul::pop_back() {
    if (sz == 0) throw "Нема";
    sz--;
    if (sz == 0) {
        delete head;
        head = nullptr;
        return;
    }
    node * el = head;
    while ((*(*el).next).next != head) {
        el = (*el).next;
    }
    node * next_el = (*el).next;
    delete next_el;
    (*el).next = head;
}
void Circul::pop_front() {
    if (sz == 0) throw "Нема";
    sz--;
    if (sz == 0) {
        delete head;
        head = nullptr;
        return;
    }
    node * el = head;
    while ((*el).next != head) {
        el = (*el).next;
    }
    (*el).next = (*head).next;
    delete head;
    head =  (*el).next;
}
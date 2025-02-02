#include "segtree.h"

void segtree::build(int x, int lx, int rx) {
    if (lx == rx - 1) {
        tree[x] = node(this->array[lx], 0);
        return;
    }
    int m = (lx + rx) / 2;
    build(x * 2 + 1, lx, m);
    build(x * 2 + 2, m, rx);
    tree[x] = unite(tree[x * 2 + 1], tree[x * 2 + 2]);
}

segtree::node segtree::ask(int x, int lx, int rx, int l, int r) {
    if (lx >= l && rx <= r) return this->tree[x];
    if (rx <= l || lx >= r) return this->NEUTRAL;
    this->push(x, lx, rx);
    int m = (lx + rx) / 2;
    node q1 = ask(x * 2 + 1, lx, m, l, r);
    node q2 = ask(x * 2 + 2, m, rx, l, r);
    return unite(q1, q2);
}

void segtree::add(int x, int lx, int rx, int l, int r, int val){
    this->last_type = 0;
    if (lx >= l && rx <= r) {
        tree[x].max += val;
        tree[x].min += val;
        tree[x].sum += val * (rx - lx);
        tree[x].psh += val;
        return;
    }
    if (rx <= l || lx >= r) return;
    this->push(x, lx, rx);
    int m = (lx + rx) / 2;
    this->add(x * 2 + 1, lx, m, l, r, val);
    this->add(x * 2 + 2, m, rx, l, r, val);
    tree[x] = this->unite(tree[x * 2 + 1], tree[x * 2 + 2]);
}

void segtree::set(int x, int lx, int rx, int l, int r, int val){
    this->last_type = 1;
    if (lx >= l && rx <= r) {
        tree[x].sum = (rx - lx) * val;
        tree[x].max = val;
        tree[x].min = val;
        tree[x].psh = val;
        return;
    }
    if (rx <= l || lx >= r) return;
    this->push(x, lx, rx);
    int m = (lx + rx) / 2;
    this->set(x * 2 + 1, lx, m, l, r, val);
    this->set(x * 2 + 2, m, rx, l, r, val);
    tree[x] = this->unite(tree[x * 2 + 1], tree[x * 2 + 2]);
}
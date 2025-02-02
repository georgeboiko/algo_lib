#pragma once
#include <vector>
#include "../constants.h"

class segtree
{
    private:
        struct node{
            int sum, min, max, psh;
            node(){}
            node(int elem, int psh){
                this->sum = elem;
                this->max = elem;
                this->min = elem;
                this->psh = psh;
            }
            node(int sum, int max, int min, int psh){
                this->sum = sum;
                this->max = max;
                this->min = min;
                this->psh = psh;
            }
        };

        std::vector<int> array;
        std::vector<node> tree;

        const node NEUTRAL = node(0, -INF, INF, INF);

        node unite(const node& a, const node& b){
            return node(
                a.sum + b.sum,
                std::max(a.max, b.max),
                std::min(a.min, b.min),
                INF
            );
        }

        void push(int x, int lx, int rx){
            if (lx == rx - 1 || tree[x].psh == INF) return;
            int m = (lx + rx) / 2;

            if (this->last_type == 1){
                tree[x * 2 + 1].max = tree[x * 2 + 1].min = tree[x * 2 + 1].sum = tree[x * 2 + 1].psh = 0;
                tree[x * 2 + 2].max = tree[x * 2 + 2].min = tree[x * 2 + 2].sum = tree[x * 2 + 2].psh = 0;    
            }

            tree[x * 2 + 1].max += tree[x].psh;
            tree[x * 2 + 1].min += tree[x].psh;
            tree[x * 2 + 1].sum += (m - lx) * tree[x].psh;
            tree[x * 2 + 1].psh += tree[x].psh;

            tree[x * 2 + 2].max += tree[x].psh;
            tree[x * 2 + 2].min += tree[x].psh;
            tree[x * 2 + 2].sum += (rx - m) * tree[x].psh;
            tree[x * 2 + 2].psh += tree[x].psh;
            
            tree[x].psh = INF;
        }

    public:
        int last_type;
        void build(int x, int lx, int rx);
        void set(int x, int lx, int rx, int l, int r, int val);
        void add(int x, int lx, int rx, int l, int r, int val);
        node ask(int x, int lx, int rx, int l, int r);

        segtree(std::vector<int> a){
            this->array = a;
            this->tree.resize(4*a.size() + 4);
            this->build(0, 0, a.size());
        }
};
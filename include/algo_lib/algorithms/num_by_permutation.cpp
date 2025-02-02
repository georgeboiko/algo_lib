#include "num_by_permutation.h"
#include <iostream>

long long num_by_permutation(std::vector<int> a){
    std::vector<long long> fact(a.size()+1);
    fact[0] = fact[1] = 1;
    for (int i = 2; i <= a.size(); ++i) fact[i] = fact[i-1] * i;
    long long ans = 0;
    for (int i = 0; i < a.size(); ++i) {
        int inv = 0;
        for (int j = i+1; j < a.size(); ++j) {
            if (a[i] > a[j]) ++inv;
        }
        ans += inv * fact[a.size() - i - 1];
    }
    return ans;
}
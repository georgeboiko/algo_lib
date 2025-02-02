#include "permutation_by_num.h"

std::vector<int> permutation_by_num(int num, int len){
    std::vector<int>ans(len), used(len);
    std::vector<long long> fact(len+1);
    fact[0] = fact[1] = 1;
    for (int i = 2; i <= len; ++i) fact[i] = fact[i-1] * i;
    for (int i = 0; i < len; ++i) {
        int w = num / fact[len - i - 1];
        num %= fact[len - i - 1];
        int cur = 0;
        for (int j = 1; j <= len; ++j) {
            if (!used[j-1]) {
                ++cur;
                if (cur == w + 1) {
                    ans[i] = j;
                    used[j - 1] = 1;
                }
            }
        }
    }
    return ans;
}
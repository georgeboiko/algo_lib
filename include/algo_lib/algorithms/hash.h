#pragma once
#include <string>
#include <vector>

class Hash
{
    private:
        std::string s;
        std::vector<long long>pows, h;
        long long p = 239017;
    public:
        Hash(const std::string& s, const long long p = 239017) {
            this->s = s;
            this->p = p;
            pows.resize(s.size()+1);
            h.resize(s.size() + 1);
            h[0] = 0, pows[0] = 1;
            for (int i = 0; i < s.size(); ++i) {
                h[i + 1] = h[i] * p + s[i];
                pows[i + 1] = pows[i] * p;
            }
        }
        long long getHash(int l, int r) {
            return h[r+1] - h[l] * pows[r - l + 1];
        }
};
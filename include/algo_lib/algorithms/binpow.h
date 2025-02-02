#pragma once

template <typename T> 
T binpow(T a, T n, T mod) {
    if (n == 0) return 1;
    if (n % 2 == 0) return binpow((a * a) % mod, n / 2, mod);
    else return (a * binpow(a, n - 1, mod)) % mod;
}
#include "crypto_math.h"

mpz_class powerMod(mpz_class base, mpz_class exp, mpz_class mod) {
    mpz_class res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

// возврат нода, а x и y меняются по ссылке
mpz_class gcdExtended(mpz_class a, mpz_class b, mpz_class &x, mpz_class &y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    mpz_class x1, y1;
    mpz_class d = gcdExtended(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

bool isPrime(mpz_class n) {
    return mpz_probab_prime_p(n.get_mpz_t(), 25) != 0;
}

mpz_class modInverse(mpz_class a, mpz_class m) {
    mpz_class x, y;
    mpz_class g = gcdExtended(a, m, x, y);
    if (g != 1) {
        return -1;
    }
    mpz_class res = (x % m + m) % m;
    return res;
}
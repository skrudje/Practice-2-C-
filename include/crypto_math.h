#ifndef CRYPTO_MATH_H
#define CRYPTO_MATH_H

#include <iostream>
#include <gmpxx.h>

using namespace std;

// для результата расширенного евклида
struct GCDResult {
    mpz_class d; // нод
    mpz_class x;
    mpz_class y;
};

mpz_class powerMod(mpz_class base, mpz_class exp, mpz_class mod);
mpz_class gcdExtended(mpz_class a, mpz_class b, mpz_class &x, mpz_class &y);
bool isPrime(mpz_class n);
mpz_class modInverse(mpz_class a, mpz_class m);

#endif
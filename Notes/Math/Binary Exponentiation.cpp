#include "../../Template.cpp"
// Binary Exponentiation

// Recursive implementation
ll binpow(long long a, long long b) {
  if (b == 0)
    return 1;
  long long res = binpow(a, b / 2);
  if (b % 2)
    return res * res * a;
  else
    return res * res;
}

// Iterative implementation
ll binpow(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    if (b & 1)
      res = res * a;
    a = a * a;
    b >>= 1;
  }
  return res;
}

// Ternary operator recursive implementation
ll binpow(ll a, ll b) {
  return b ? (binpow(a * a, b >> 1) * (b & 1 ? a : 1)) : 1;
}

// Ternary operator recursive implementation with modulo
ll binpow(ll a, ll b) {
  return b ? (binpow(a * a % MOD, b >> 1) * (b & 1 ? a : 1)) % MOD : 1;
}
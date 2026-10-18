// #pragma GCC optimize("O3")
// #pragma GCC target("avx,avx2,bmi,bmi2,popcnt,lzcnt")

#include <cstdint>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::istream;
using std::ostream;
using std::pair;
using std::vector;
using Ll = long long;
using Db = long double;
using Ld = long double;
using Ull = unsigned long long;
using Uint = unsigned int;
using Pii = pair<int, int>;
[[maybe_unused]] constexpr int cInf = 1e9 + 7;
[[maybe_unused]] constexpr Ll cInf2 = 1e18;
[[maybe_unused]] constexpr Db cEps = 1e-7;

[[maybe_unused]] static istream& operator>>(istream& is, __int128& a) {
  long long b;
  is >> b;
  a = b;
  return is;
}

[[maybe_unused]] static ostream& operator<<(ostream& os, const __int128& a) {
  return os << (long long)a;
}

void RadixSort(vector<uint64_t>& a) {
  constexpr int bits = 8;
  constexpr int digits = 64;
  constexpr int base = 1 << bits;
  constexpr uint64_t mask = base - 1;
  vector<uint64_t> tmp(a.size());
  vector<Uint> cnt(base);
  for (Uint shift = 0; shift < digits; shift += bits) {
    for (Uint& x : cnt) {
      x = 0;
    }
    for (const uint64_t& x : a) {
      cnt[(x >> shift) & mask]++;
    }
    for (Uint i = 1; i < base; i++) {
      cnt[i] += cnt[i - 1];
    }
    for (int i = (int)a.size() - 1; i >= 0; i--) {
      tmp[--cnt[(a[i] >> shift) & mask]] = a[i];
    }
    a.swap(tmp);  // O(1)
  }
}

signed main() {
#ifndef LOCAL
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
#endif
  std::ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  Uint n;
  cin >> n;
  vector<uint64_t> a(n);
  for (uint64_t& x : a) {
    cin >> x;
  }
  RadixSort(a);
  for (const uint64_t& x : a) {
    cout << x << '\n';
  }
  return 0;
}

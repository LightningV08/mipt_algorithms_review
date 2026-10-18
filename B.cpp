// #pragma GCC optimize("O3")
// #pragma GCC target("avx,avx2,bmi,bmi2,popcnt,lzcnt")

#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::istream;
using std::ostream;
using std::pair;
using std::swap;
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

inline void InsertSort(vector<int>& v, const int& l, const int& r) {
  for (int k = l + 1; k < r; k++) {
    for (int i = k; i > l && v[i] < v[i - 1]; i--) {
      swap(v[i], v[i - 1]);
    }
  }
}

Pii Partition(vector<int>& v, const int& l, const int& r, const int& p) {
  int a = l;
  int i = l;
  int b = r;
  while (i < b) {
    if (v[i] < p) {
      swap(v[a++], v[i++]);
    } else if (v[i] > p) {
      swap(v[i], v[--b]);
    } else {
      i++;
    }
  }
  return {a, b};
}

int NthElement(vector<int>& v, int l, int r, const int& k) {
  while (r - l > 5) {
    int j = l;
    for (int i = l; i < r; i += 5) {
      const int end = i + 5 < r ? i + 5 : r;
      InsertSort(v, i, end);
      swap(v[j++], v[(i + end) >> 1]);
    }
    const int p = NthElement(v, l, j, (l + j) >> 1);
    const Pii mid = Partition(v, l, r, p);
    if (k < mid.first) {
      r = mid.first;
    } else if (k >= mid.second) {
      l = mid.second;
    } else {
      return p;
    }
  }
  InsertSort(v, l, r);
  return v[k];
}

signed main() {
#ifndef LOCAL
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
#endif
  std::ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  int k;
  int a0;
  int a1;
  cin >> n >> k >> a0 >> a1;
  vector<int> a(n);
  a[0] = a0;
  if (n > 1) {
    a[1] = a1;
  }
  constexpr int mod = 10004321;
  constexpr int x = 123;
  constexpr int y = 45;
  for (int i = 2; i < n; i++) {
    a[i] = (a[i - 1] * x + a[i - 2] * y) % mod;
  }
  cout << NthElement(a, 0, n, k - 1) << '\n';
  return 0;
}

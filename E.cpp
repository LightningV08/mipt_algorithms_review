// #pragma GCC optimize("O3")
// #pragma GCC target("avx,avx2,bmi,bmi2,popcnt,lzcnt")

#include <iomanip>
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

signed main() {
#ifndef LOCAL
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
#endif
  std::ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> b(n);
  for (int& x : a) {
    cin >> x;
  }
  for (int& x : b) {
    cin >> x;
  }
  int q;
  cin >> q;
  while (q-- != 0) {
    int x;
    cin >> x;
    int l = -1;
    int r = n;
    while (r - l > 1) {
      const int cMid = (l + r) >> 1;
      if (a[cMid] + x < b[cMid]) {
        l = cMid;
      } else {
        r = cMid;
      }
    }
    if (l != -1 && (r == n || b[l] < a[r] + x)) {
      r = l;
    }
    cout << r + 1 << '\n';
  }
}

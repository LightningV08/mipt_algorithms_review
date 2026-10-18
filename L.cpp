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
using std::string;
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

inline bool Check(string s, const string& t, const vector<int>& p, const int& n,
                  const int& m, const int& mid) {
  for (int i = 0; i < mid; i++) {
    s[p[i] - 1] = '_';
  }
  int j = 0;
  for (int i = 0; i < n && j < m; i++) {
    if (s[i] == t[j]) {
      j++;
    }
  }
  return j == m;
}

signed main() {
#ifndef LOCAL
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
#endif
  std::ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  string s;
  string t;
  cin >> s >> t;
  const int cN = s.size();
  const int cM = t.size();
  vector<int> p(cN);
  for (int& x : p) {
    cin >> x;
  }
  int l = 0;
  int r = cN;
  while (r - l > 1) {
    const int cMid = (l + r) >> 1;
    if (Check(s, t, p, cN, cM, cMid)) {
      l = cMid;
    } else {
      r = cMid;
    }
  }
  cout << l;
}

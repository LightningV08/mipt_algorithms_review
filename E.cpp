// #pragma GCC optimize("O3")
// #pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")

#include <deque>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::deque;
using std::istream;
using std::ostream;
using std::pair;
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
  int x;
  cin >> n;
  char c;
  deque<int> a;
  deque<int> b;
  while (n-- != 0) {
    cin >> c;
    if (c == '+') {
      cin >> x;
      if (a.empty()) {
        a.push_back(x);
      } else {
        if (a.size() == b.size()) {
          a.push_back(b.front());
          b.pop_front();
        }
        b.push_back(x);
      }
    } else if (c == '*') {
      cin >> x;
      if (a.size() == b.size()) {
        a.push_back(x);
      } else {
        b.push_front(x);
      }
    } else {
      cout << a.front() << '\n';
      a.pop_front();
      if (a.size() != b.size()) {
        a.push_back(b.front());
        b.pop_front();
      }
    }
  }
  return 0;
}

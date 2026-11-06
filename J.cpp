// #pragma GCC optimize("O3")
// #pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")

#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::istream;
using std::ostream;
using std::pair;
using std::string;
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

struct Heap {
  vector<pair<Ll, int>> t;
  vector<int> pos;

  explicit Heap(const int& n) : t(1), pos(n + 1, -1) {}

  void Exchange(const int& a, const int& b) {
    swap(t[a], t[b]);
    pos[t[a].second] = a, pos[t[b].second] = b;
  }

  void Up(int v) {
    while (v != 1) {
      if (t[v] >= t[v >> 1]) {
        break;
      }
      Exchange(v, v >> 1);
      v >>= 1;
    }
  }

  void Down(int v) {
    while ((v << 1) < (int)t.size()) {
      int u = v << 1;
      if (u + 1 < (int)t.size() && t[u + 1] < t[u]) {
        ++u;
      }
      if (!(t[u] < t[v])) {
        break;
      }
      Exchange(u, v);
      v = u;
    }
  }

  void Insert(const Ll& x, const int& id) {
    pos[id] = (int)t.size();
    t.emplace_back(x, id);
    Up(pos[id]);
  }

  void ExtractMin() {
    Exchange(1, (int)t.size() - 1);
    pos[t.back().second] = -1;
    t.pop_back();
    Down(1);
  }

  void Decrease(const int& id, const Ll& x) {
    t[pos[id]].first -= x;
    Up(pos[id]);
  }
};

signed main() {
#ifndef LOCAL
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
#endif
  std::ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int q;
  cin >> q;
  Heap h(q);
  string s;
  for (int i = 1; i <= q; ++i) {
    cin >> s;
    if (s == "insert") {
      Ll x;
      cin >> x;
      h.Insert(x, i);
    } else if (s == "getMin") {
      cout << h.t[1].first << '\n';
    } else if (s == "extractMin") {
      h.ExtractMin();
    } else {
      int id;
      Ll x;
      cin >> id >> x;
      h.Decrease(id, x);
    }
  }
  return 0;
}

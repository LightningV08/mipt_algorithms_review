// #pragma GCC optimize("O3")
// #pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")

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

constexpr int cClearCommand = 6;

struct Heap {
  vector<Pii> t;
  vector<int> pos;
  bool rev;

  Heap(const int& n, const bool& flag) : t(1), pos(n + 1, -1), rev(flag) {}

  bool Better(const int& a, const int& b) const {
    if (t[a].first == t[b].first) {
      return t[a].second < t[b].second;
    }
    return rev ? t[a].first > t[b].first : t[a].first < t[b].first;
  }

  void Exchange(const int& a, const int& b) {
    swap(t[a], t[b]);
    pos[t[a].second] = a, pos[t[b].second] = b;
  }

  void Up(int v) {
    while (v != 1) {
      if (!Better(v, v >> 1)) {
        break;
      }
      Exchange(v, v >> 1);
      v >>= 1;
    }
  }

  void Down(int v) {
    while ((v << 1) < (int)t.size()) {
      int u = v << 1;
      if (u + 1 < (int)t.size() && Better(u + 1, u)) {
        ++u;
      }
      if (!Better(u, v)) {
        break;
      }
      Exchange(u, v);
      v = u;
    }
  }

  void Insert(const int& x, const int& id) {
    pos[id] = (int)t.size();
    t.emplace_back(x, id);
    Up(pos[id]);
  }

  void Erase(const int& id) {
    const int v = pos[id];
    Exchange(v, (int)t.size() - 1);
    pos[id] = -1;
    t.pop_back();
    if (v == (int)t.size()) {
      return;
    }
    if (v != 1 && Better(v, v >> 1)) {
      Up(v);
    } else {
      Down(v);
    }
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
  Heap a(q, false);
  Heap b(q, true);
  for (int i = 1; i <= q; ++i) {
    int c;
    cin >> c;
    if (c == 0) {
      int x;
      cin >> x;
      a.Insert(x, i), b.Insert(x, i);
      cout << "ok\n";
    } else if (c == 5) {
      cout << a.t.size() - 1 << '\n';
    } else if (c == cClearCommand) {
      a.t.resize(1), b.t.resize(1);
      cout << "ok\n";
    } else if (a.t.size() == 1) {
      cout << "error\n";
    } else {
      const Pii x = c <= 2 ? a.t[1] : b.t[1];
      cout << x.first << '\n';
      if (c == 1 || c == 3) {
        a.Erase(x.second), b.Erase(x.second);
      }
    }
  }
  return 0;
}

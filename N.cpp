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

struct Block {
  Ll l, len;
  int pr = -1, nxt = -1, pos = -1;
  bool free = true;
};

struct Memory {
  vector<Block> a;
  vector<int> h;

  Memory(const Ll& n, const int& q) : h(1) {
    a.reserve(q + 1);
    a.push_back({1, n});
    Insert(0);
  }

  bool Better(const int& u, const int& v) const {
    return a[u].len > a[v].len || (a[u].len == a[v].len && a[u].l < a[v].l);
  }

  void Exchange(const int& u, const int& v) {
    swap(h[u], h[v]);
    a[h[u]].pos = u, a[h[v]].pos = v;
  }

  void Up(int v) {
    while (v != 1) {
      if (!Better(h[v], h[v >> 1])) {
        break;
      }
      Exchange(v, v >> 1);
      v >>= 1;
    }
  }

  void Down(int v) {
    while ((v << 1) < (int)h.size()) {
      int u = v << 1;
      if (u + 1 < (int)h.size() && Better(h[u + 1], h[u])) {
        ++u;
      }
      if (!Better(h[u], h[v])) {
        break;
      }
      Exchange(u, v);
      v = u;
    }
  }

  void Insert(const int& id) {
    a[id].pos = (int)h.size();
    h.push_back(id);
    Up(a[id].pos);
  }

  void Erase(const int& id) {
    const int v = a[id].pos;
    Exchange(v, (int)h.size() - 1);
    h.pop_back();
    a[id].pos = -1;
    if (v == (int)h.size()) {
      return;
    }
    if (v != 1 && Better(h[v], h[v >> 1])) {
      Up(v);
    } else {
      Down(v);
    }
  }

  int Allocate(const Ll& len) {
    if (h.size() == 1 || a[h[1]].len < len) {
      return -1;
    }
    const int v = h[1];
    Erase(v);
    if (a[v].len > len) {
      const int u = (int)a.size();
      a.push_back({a[v].l + len, a[v].len - len, v, a[v].nxt});
      if (a[v].nxt != -1) {
        a[a[v].nxt].pr = u;
      }
      a[v].nxt = u, a[v].len = len;
      Insert(u);
    }
    a[v].free = false;
    return v;
  }

  void Release(const int& v) {
    if (a[v].pr != -1 && a[a[v].pr].free) {
      const int u = a[v].pr;
      Erase(u);
      a[v].l = a[u].l, a[v].len += a[u].len, a[v].pr = a[u].pr;
      if (a[v].pr != -1) {
        a[a[v].pr].nxt = v;
      }
      a[u].free = false;
    }
    if (a[v].nxt != -1 && a[a[v].nxt].free) {
      const int u = a[v].nxt;
      Erase(u);
      a[v].len += a[u].len, a[v].nxt = a[u].nxt;
      if (a[v].nxt != -1) {
        a[a[v].nxt].pr = v;
      }
      a[u].free = false;
    }
    a[v].free = true;
    Insert(v);
  }
};

signed main() {
#ifndef LOCAL
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
#endif
  std::ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  Ll n;
  int q;
  cin >> n >> q;
  Memory h(n, q);
  vector<int> pos(q + 1, -1);
  for (int i = 1; i <= q; ++i) {
    Ll x;
    cin >> x;
    if (x > 0) {
      pos[i] = h.Allocate(x);
      cout << (pos[i] == -1 ? -1 : h.a[pos[i]].l) << '\n';
    } else {
      const int id = (int)-x;
      if (pos[id] == -1) {
        continue;
      }
      h.Release(pos[id]);
      pos[id] = -1;
    }
  }
  return 0;
}

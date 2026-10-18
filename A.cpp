// #pragma GCC optimize("O3")
// #pragma GCC target("avx,avx2,bmi,bmi2,popcnt,lzcnt")

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

void MergeSort(vector<Pii>& v, const int& l, const int& r) {
  if (r - l <= 1) {
    return;
  }
  const int mid = (l + r) >> 1;
  MergeSort(v, l, mid);
  MergeSort(v, mid, r);
  vector<Pii> tmp;
  tmp.reserve(r - l);
  int a = l;
  int b = mid;
  while (a < mid && b < r) {
    if (v[a].first < v[b].first ||
        (v[a].first == v[b].first && v[a].second > v[b].second)) {
      tmp.push_back(v[a++]);
    } else {
      tmp.push_back(v[b++]);
    }
  }
  for (; a < mid; a++) {
    tmp.push_back(v[a]);
  }
  for (; b < r; b++) {
    tmp.push_back(v[b]);
  }
  for (int i = 0; i < r - l; i++) {
    v[i + l] = tmp[i];
  }
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
  vector<Pii> a(n);
  for (Pii& x : a) {
    cin >> x.first >> x.second;
  }
  MergeSort(a, 0, n);
  vector<int> l;
  vector<int> r;
  l.reserve(n), r.reserve(n);
  l.push_back(a[0].first), r.push_back(a[0].second);
  for (int i = 1; i < n; i++) {
    if (a[i].second <= r.back()) {
      continue;
    }
    if (a[i].first > r.back()) {
      l.push_back(a[i].first), r.push_back(a[i].second);
    } else {
      r.back() = a[i].second;
    }
  }
  cout << l.size() << '\n';
  for (int i = 0; i < (int)l.size(); i++) {
    cout << l[i] << ' ' << r[i] << '\n';
  }
  return 0;
}

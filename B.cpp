#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::exp;
using std::fixed;
using std::log;
using std::setprecision;
using std::vector;

using Ld = long double;

constexpr int cPrecision = 10;

int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<Ld> prefix_logs(n + 1);
  for (int i = 0; i < n; i++) {
    Ld value;
    cin >> value;
    prefix_logs[i + 1] = prefix_logs[i] + log(value);
  }
  cout << fixed << setprecision(cPrecision);
  int q;
  cin >> q;
  while (q-- != 0) {
    int l;
    int r;
    cin >> l >> r;
    cout << exp((prefix_logs[r + 1] - prefix_logs[l]) / (r - l + 1)) << '\n';
  }
}

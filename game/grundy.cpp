#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<long long> moves = {1,3,4};
  int period = 5; // detected from pattern

  // Precompute Grundy for period
  vector<int> grundy(period);
  grundy[0] = 0;
  for (int i = 1; i < period; i++) {
    set<int> s;
    for (auto mv : moves) {
      if (i - mv >= 0) s.insert(grundy[(i-mv)%period]);
    }
    int g = 0;
    while (s.count(g)) g++;
    grundy[i] = g;
  }
  int n;
  cin >> n;
  vector<long long> a(n);
  long long totalXor = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    totalXor ^= grundy[a[i] % period];
  }
  if (totalXor == 0) cout << "Second\n";
  else cout << "First\n";
}

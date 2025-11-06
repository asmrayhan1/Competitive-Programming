#include<bits/stdc++.h>
#define ll unsigned long long
#define f first
#define s second
using namespace std;

const int N = 2e5;
vector<ll> a(N);

class SegmentTree {
  public:
  int n;
  vector<ll> tree;
  SegmentTree(int n) : tree(2 * n + 10), n(n){};

  void build() {
    for (int i = 1; i <= n; i++) 
      tree[n + i] = a[i];
    for (int i = n; i > 0; i--) 
      tree[i] = tree[i << 1] + tree[i << 1 | 1];
  }

  void upd(int pos, ll value) {
    for (tree[pos += n] += value; pos > 1; pos >>= 1)
      tree[pos >> 1] = tree[pos] + tree[pos ^ 1]; // Range sum
  }

  ll query(int l, int r) {
    ll res = 0;
    for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
      if (l & 1) res += tree[l++];
      if (r & 1) res += tree[--r];
    }
    return res;
  }
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  SegmentTree st(5);
  st.build();
  st.upd(1, 10); // 1 base index 
  st.query(2, 5); // [2, 5] inclusive
}

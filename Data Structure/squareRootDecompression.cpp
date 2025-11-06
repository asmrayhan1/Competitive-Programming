#include <bits/stdc++.h>
#define ll long long
using namespace std;

// 0 base index 

const int N = 2e5 + 10;
int n, q, m;
vector<ll> a(N), S(N);
vector<map<ll, ll>> blk;

void build() {
    m = sqrt(n);
    if (m * m != n) m++;
    blk.assign(m, {});
    for (int i = 0; i < n; i++) {
        blk[i / m][a[i]]++;
    }
}

void update(int idx, ll val) {
    int b = idx / m;
    blk[b][a[idx]]--;
    if (blk[b][a[idx]] == 0) blk[b].erase(a[idx]);
    a[idx] = val;
    blk[b][val]++;
}

ll query(int L, int R, ll s, ll cur) {
    ll ans = 0;

    if (L / m == R / m) {
        for (int i = L; i <= R; i++) {
            if (S[i] - cur == s) ans++;
        }
        return ans;
    }

    int st = L / m, ed = R / m;

    // Left partial block
    if (L % m != 0) {
        int z = ((L + m) / m) * m;
        for (int i = L; i < min(z, n); ++i) {
            if (S[i] - cur == s) ans++;
        }
        st = (L + m) / m;
    }

    // Right partial block
    if (R % m != m - 1) {
        int z = (R / m) * m;
        for (int i = R; i >= z; --i) {
            if (S[i] - cur == s) ans++;
        }
        ed = (R / m) - 1;
    }

    // Full blocks
    for (int i = st; i <= ed; ++i) {
        if (blk[i].count(s + cur)) ans += blk[i][s + cur];
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> S[i]; // optional (for condition)

    build();

    while (q--) {
        int op;
        cin >> op;
        if (op == 0) {
            int idx; ll val;
            cin >> idx >> val;
            update(idx, val);
        } else {
            int L, R; ll s, cur;
            cin >> L >> R >> s >> cur;
            cout << query(L, R, s, cur) << "\n";
        }
    }

    return 0;
}

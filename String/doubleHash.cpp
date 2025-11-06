#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll pw(ll x, ll y, ll p) {
    ll res = 1;
    x %= p;
    while (y > 0) {
        if (y & 1) res = res * x % p;
        x = x * x % p;
        y >>= 1;
    }
    return res;
}

ll inv(ll x, ll p) {
    return pw(x, p - 2, p);
}

class Hs {
private:
    int len;
    const ll m1 = 1000000007, m2 = 1000000009;
    const ll p1 = 911382629, p2 = 357142857;
    vector<ll> h1, h2, pw1, pw2, ip1, ip2;

public:
    Hs() : len(0) {
        pw1.push_back(1); pw2.push_back(1);
        h1.push_back(0); h2.push_back(0);
        ip1.push_back(1); ip2.push_back(1);
    }

    Hs(const string& s) : Hs() {
        for (char c : s) add(c);
    }

    void add(char c) {
        ll nh1 = (h1.back() + (c - '0' + 1) * pw1.back()) % m1;
        ll nh2 = (h2.back() + (c - '0' + 1) * pw2.back()) % m2;
        h1.push_back(nh1); h2.push_back(nh2);
        len++;

        ll npw1 = (pw1.back() * p1) % m1;
        ll npw2 = (pw2.back() * p2) % m2;
        pw1.push_back(npw1); pw2.push_back(npw2);

        static bool done = false;
        static ll ipv1, ipv2;
        if (!done) {
            ipv1 = inv(p1, m1);
            ipv2 = inv(p2, m2);
            done = true;
        }
        ll nip1 = (ip1.back() * ipv1) % m1;
        ll nip2 = (ip2.back() * ipv2) % m2;
        ip1.push_back(nip1); ip2.push_back(nip2);
    }

    int sz() const { return len; }

    pair<ll, ll> sub(int l, int r) const {
        if (l < 0 || r >= len || l > r)
            throw out_of_range("Invalid substring indices");
        ll ch1 = (h1[r + 1] - h1[l] + m1) % m1;
        ch1 = (ch1 * ip1[l]) % m1;

        ll ch2 = (h2[r + 1] - h2[l] + m2) % m2;
        ch2 = (ch2 * ip2[l]) % m2;

        return {ch1, ch2};
    }

    bool operator==(const Hs& o) const {
        return (h1 == o.h1) && (h2 == o.h2);
    }
};

int main() {
    Hs h;
    h.add('a');
    auto cur = h.sub(0, 0);
    cout << cur.first << " " << cur.second << " " << h.sz() << endl;
}

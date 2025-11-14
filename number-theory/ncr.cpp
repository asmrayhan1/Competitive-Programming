#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll n = 10, mod = 1e9 + 7;
 
ll binpow(ll a, ll b){
    ll res = 1;
    while (b > 0) {
        if (b & 1) {
            res = (res * a) % mod;
        }
        a = (a * a) % mod;
        b /= 2;
    }
    return res;
}

int main() {
  vector<ll> ncr(n + 1, 1);
  for(int i = 0; i <= n; i++){
    // ncr[i] = (factorial[n] * binpow((factorial[i] * factorial[n - i]) % mod, mod - 2)) % mod;
  }
}

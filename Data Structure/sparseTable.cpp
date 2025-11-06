#include<bits/stdc++.h>
#define ll int
#define f first
#define s second
using namespace std;

int const N = 2e5 + 10;

int lg[N + 1], table[N][25]; 
vector<ll> arr(N), b(N);

// 0 base index
void buildSparseTable(int n) { 
  for (int i = 0; i < n; i++) 
    table[i][0] = arr[i]; 
  for (int j = 1; (1 << j) <= n; j++) 
    for (int i = 0; i <= n - (1 << j); i++) 
      table[i][j] = __gcd(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]); 
}

void lgg(int n){
  lg[0] = lg[1] = 0;
  for (int i = 2; i <= n; i++) lg[i] = lg[i / 2] + 1;
}

// Returns arr[L..R] inclusive 
int query(int L, int R) {
  int j = lg[R - L + 1]; // (int) log2(R - L + 1); 
  return __gcd(table[L][j], table[R - (1 << j) + 1][j]); 
} 

int main() {
  lgg(10);
  buildSparseTable(10);
}

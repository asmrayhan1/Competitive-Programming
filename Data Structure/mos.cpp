#include<bits/stdc++.h>
#define ll unsigned long long
#define f first
#define s second
using namespace std;

const int N = 2e6 + 10;

struct qry{
	int l, r, id, x, y;
	friend bool operator<(qry a,qry b){
		if(a.l/500!=b.l/500)return a.l/500<b.l/500;
		return a.r<b.r;
	}
}Q[N];

int main() {
  int n, k, query; cin >> n >> k >> query;
  vector<ll> a(N + 10), c(N + 10), ans(query + 10);
  for (int i = 1; i <= n; i++){
    int l, r; cin >> l >> r;
    a[l]++; a[r + 1]--;
  }
  for (int i = 1; i <= N; i++){
    a[i] += a[i - 1];
  }
  
  // template start 
  for(int i = 1; i <= query; i++) {
    cin >> Q[i].l >> Q[i].r;
    Q[i].id = i;
  }
  sort(Q + 1, Q + query + 1); // 1 index base 
  int l = 1, r = 0, res = 0;
  for(int i = 1; i <= query; i++) {
    while(r<Q[i].r){
			r++;
			if (a[r] >= k) res++;
		}
	  while(l>Q[i].l){
		  l--;
		  if (a[l] >= k) res++;
		}
	  while(r>Q[i].r){
			if (a[r] >= k) res--;
      r--;
	  }
	  while(l<Q[i].l){
		  if (a[l] >= k) res--;
      l++;
		}
    ans[Q[i].id] = res;
  }
  for (int i = 1; i <= query; i++) cout<<ans[i]<<endl;
}

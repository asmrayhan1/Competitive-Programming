#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll dp[20][20][20][20];

void getDigits(long long x, vector <int> &digit){
  while (x){
    digit.push_back(x % 10);
    x /= 10;
  }
}

long long digitSum(int idx, int cnt, int parent, int child, int tight, int check, vector <int> &digit){
  if (idx == -1) return cnt;
  if (dp[idx][cnt][parent][child] != -1 and tight != 1){
    return dp[idx][cnt][parent][child];
  } 
  long long ret = 0;
  int k = (tight)? digit[idx] : 9;
  for (int i = 0; i <= k ; i++){
    int newTight = (k == i) && tight;
    int cur = cnt; 
    int ok = check;
    int x = child, y = i;
    if (check == -1 && i == 0) y = -1;
    else ok = 0;
    if (parent >= 0 && child >= 0){
      if (parent < child && child > i) cur++;
      else if (parent > child && child < i) cur++;
    }
    ret += digitSum(idx-1, cur, x, y, newTight, ok, digit);
  } 
  if (!tight){
    dp[idx][cnt][parent][child] = ret;
    // printf("idx %d, sum %d, tight %d,  ret: %lld\n", idx, sum,tight,ret);
  }
  return ret;
}
 
ll rec(long long a, long long b){
  vector<int> digitA, digitB;
  getDigits(a-1, digitA);
  long long ans1 = digitSum(digitA.size()-1, 0, -1, -1, 1, -1, digitA);
  getDigits(b, digitB);
  long long ans2 = digitSum(digitB.size()-1, 0, -1, -1, 1, -1, digitB);
  return (ans2 - ans1);
}

/*
long long dp[20][200][9999];
map<ll, ll> mp; 
int c;
long long digitSum(int idx, ll sum, ll product, int tight, int ok, vector <ll> &digit){
  if (idx == -1) return 0;
  if (!mp[product]){
    c++; 
    mp[product] = c;
  } 
  ll productId = mp[product];
  if (dp[idx][sum][productId] != -1 and tight != 1){
    return dp[idx][sum][productId];
  } 
  ll ret = 0;
  int k = (tight)? digit[idx] : 9;
  for (ll i = 0; i <= k ; i++){
    int newTight = (k == i && tight)? 1 : 0;
    int check = (ok == -1 && i == 0)? -1 : 0;
    ll Product = product;
    if (check == 0) Product *= i;
    ret += digitSum(idx-1, sum + i, Product, newTight, check, digit);
  }
  if (!tight){
    dp[idx][sum][productId] = ret;
  }
  return ret;
}
ll ans = digitSum(digitA.size()-1, 0, 1, 1, -1, digitA);
*/

int main() {
  rec(10,20);
}

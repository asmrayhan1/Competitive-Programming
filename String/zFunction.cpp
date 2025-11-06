#include<bits/stdc++.h>
using namespace std;

int const N = 2e5 + 10;

string str;
int Z[N];

// Implements Z algorithm for pattern searching
// Fills Z array for given string str[]
void getZarr(){
  int n = str.length();
  int L, R, k;
   
  Z[0] = n; // start index is lcp itself
    
  // [L,R] make a window which matches with prefix of s
  L = R = 0;
  for (int i = 1; i < n; ++i){
    if (i > R) {
      L = R = i;
      while (R<n && str[R-L] == str[R]){
        R++;
      }
      Z[i] = R-L;
      R--;
    } else {
      k = i-L;
      if (Z[k] < R-i+1){
        Z[i] = Z[k];
      } else {
        // else start from R and check manually
        L = i;
        while (R<n && str[R-L] == str[R]){
          R++;
        }
        Z[i] = R-L;
        R--;
      }
    }
  }
}

int main(){
  getZarr(); 
}

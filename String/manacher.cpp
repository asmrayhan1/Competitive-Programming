#include<bits/stdc++.h>
using namespace std;

std::vector<int> manacher(const std::string &s) {
  std::string T = "$#";
  for (char c : s) {
    T += c;
    T += "#";
  }
  int m = T.length();
  T += '&';
  int maxRight = 0, mid = 0;
  std::vector<int> L(m);
  for (int i = 1; i < m; ++i) {
    L[i] = i < maxRight ? std::min(L[2 * mid - i], maxRight - i) : 1;
    while (T[i - L[i]] == T[i + L[i]]){
      ++L[i];
    }
    if (maxRight < i + L[i]) {
      mid = i;
      maxRight = i + L[i];
    }
    // when i is odd or T[i] == '#', L[i] - 1 is even palindrome length 
    // when is even or T[i] == 'a-z', L[i] - 1 is odd palindrome length
    // Palindrome Start index = (i - L[i]) / 2;  [0 index]
    // Palindrome End index = (i + L[i]) / 2 - 2; [0 index]
  }
  return L;
}

int main() {
  string s;
  cin >> s;
  std::vector<int> L = manacher(s);
  for (auto i : L) cout << i << " ";
}

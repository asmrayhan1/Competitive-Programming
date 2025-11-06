#include <bits/stdc++.h>
#include <vector>
#include <string>
#define ll long long
using namespace std;


struct TrieNode {
    TrieNode* child[26];
    bool wordEnd;

    TrieNode() {
        wordEnd = false;
        for (int i = 0; i < 26; i++) {
            child[i] = nullptr;
        }
    }
};

//vector<map<> ans(100005);
vector<map<TrieNode*, ll>> g(100005);



void insertKey(TrieNode* root, const std::string& key) {
    TrieNode* curr = root;
    int l = 1;
    for (char c : key) {
        if (curr->child[c - 'a'] == nullptr) {
            TrieNode* newNode = new TrieNode();
            curr->child[c - 'a'] = newNode;
        }
        g[l][curr->child[c - 'a']]++;
        // if(l==3)cout <<"->"<<g[l][curr->child[c - 'a']]<<endl;
        curr = curr->child[c - 'a'];
        l++;
    }
    curr->wordEnd = true;
}

bool searchKey(TrieNode* root, const std::string& key) {
    TrieNode* curr = root;
    int l = 1;
    for (char c : key) {
        if (curr->child[c - 'a'] == nullptr) {
            return false;
        }
        g[l][curr->child[c - 'a']]--;
        curr = curr->child[c - 'a'];
        l++;
    }
    return curr->wordEnd;
}

bool isEmpty(TrieNode* root) {
    for (int i = 0; i < 26; i++) {
        if (root->child[i]) {
            return false;
        }
    }
    return true;
}

TrieNode* remove(TrieNode* root, std::string key, int depth = 0) {
    if (!root) {
        return nullptr;
    }

    if (depth == key.size()) {
        if (root->wordEnd) {
            root->wordEnd = false;
        }
        if (isEmpty(root)) {
            delete root;
            root = nullptr;
        }
        return root;
    }

    int index = key[depth] - 'a';
    root->child[index] = remove(root->child[index], key, depth + 1);

    if (isEmpty(root) && !root->wordEnd) {
        delete root;
        root = nullptr;
    }
    return root;
}

int main() {
  TrieNode* root = new TrieNode();
  
  int t, r = 1;
  cin >> t;
  string s[t + 1];
  while (t--){
    int n, k, l;
    cin >> n;
    if (n == 1){
      cin >> s[r];
      reverse(s[r].begin(), s[r].end());
      insertKey(root, s[r]);
    } else if (n == 2){
      cin >> k >> l;
      int f = 0;
      for (auto it : g[l]){
        if (it.second >= k){
          f = 1;
          break;
        }
      }
      cout << (f? "YES" : "NO") << endl;
    } else {
      cin >> l;
      if (!s[l].empty()){
        searchKey(root, s[l]);
        s[l].clear();
      }
    }
    r++;
  }
}

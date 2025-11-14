#include<bits/stdc++.h>
#define ll long long
using namespace std;
 
struct DSU {
    vector<int> par, rank, sz;
    int c;

    DSU(int n) : par(n + 1), rank(n + 1, 0), sz(n + 1, 1), c(n) {
        for (int i = 1; i <= n; i++) par[i] = i;
    }

    int find(int v) {
        if (par[v] == v) return v;
        else return par[v] = find(par[v]); // Path compression
    }

    bool same(int a, int b) {
        return find(a) == find(b);
    }

    int get_size(int v) {
        return sz[find(v)];
    }

    int count() {
        return c;
    }

    void merge(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return; // Already in the same component

        c--; // Decrease component count
        if (rank[a] > rank[b]) swap(a, b); // Union by rank

        par[a] = b;
        sz[b] += sz[a];

        if (rank[a] == rank[b]) rank[b]++;
    }
};

int main() {
    int n = 5;
    DSU dsu(n);

    // Example usage
    dsu.merge(1, 2);
    dsu.merge(3, 4);

    cout << "Are 1 and 2 in the same component? " << (dsu.same(1, 2) ? "Yes" : "No") << endl;
    cout << "Size of component containing 3: " << dsu.get_size(3) << endl;
    cout << "Number of connected components: " << dsu.count() << endl;

    dsu.merge(2, 3);

    cout << "Are 1 and 3 in the same component? " << (dsu.same(1, 3) ? "Yes" : "No") << endl;
    cout << "Size of component containing 1: " << dsu.get_size(1) << endl;
    cout << "Number of connected components: " << dsu.count() << endl;

    return 0;
}

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr auto seq(int begin, int end) { return ranges::iota_view(begin, end); }
constexpr auto seq(int end) { return ranges::iota_view(0, end); }

using Graph = vector<vector<int>>;

vector<bool> seen;
vector<int> read_list;

void dfs(Graph& g, int v) {
    seen[v] = true;

    for (auto&& nv : g[v]) {
        if (seen[nv]) continue;
        dfs(g, nv);
        read_list.push_back(nv);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    Graph g(n);
    for (int i: seq(n)) {
        int c; cin >> c;
        for (int j: seq(c)) {
            int p; cin >> p;
            g[i].push_back(p-1);
        }
    }
    
    seen.assign(n, false);
    dfs(g, 0);
    
    for (auto&& e: read_list) {
        cout << e+1 << ' ';
    }
    return 0;
}
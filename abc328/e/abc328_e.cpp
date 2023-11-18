#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr auto seq(int begin, int end) { return ranges::iota_view(begin, end); }
constexpr auto seq(int end) { return ranges::iota_view(0, end); }
#define all(v) std::ranges::begin((v)), std::ranges::end((v))

long long pow(int x, int y) {
    long long res = 1;
    for (int i=0;i<y;++i) res *= x;
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;
    ll k; cin >> k;
    vector<tuple<int,int,ll>> g(m);
    for (int i: seq(m)) {
        int u,v; cin >> u >> v;
        --u; --v;
        ll w; cin >> w;
        g[i] = {u,v,w};
    }

    int allnode = pow(2, n) - 1;
    ll result = -1;
    for (unsigned long long i=0; i<pow(2, m); ++i) {
        if (popcount(i) != n-1) continue;
        int nodes = 0;
        ll cost = 0;

        for (int j: seq(m)) {
            int flag = (i >> j) & 1;
            if (flag == 1) {
                auto& [u,v,w] = g[j];
                nodes |= (1 << u);
                nodes |= (1 << v);
                cost += w;
                cost %= k;
            }
        }
        
        if (nodes == allnode) {
            if (result == -1) result = cost;
            else result = min(result, cost);
        }
    }
    cout << result;
    return 0;
}
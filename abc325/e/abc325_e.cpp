#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr auto seq(int begin, int end) { return ranges::iota_view(begin, end); }
constexpr auto seq(int end) { return ranges::iota_view(0, end); }
#define all(v) std::ranges::begin((v)), std::ranges::end((v))

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n, a, b, c; cin >> n >> a >> b >> c;
    vector g(n, vector<ll>(n));
    for (int i: seq(n)) {
        for (int j: seq(n)) {
            cin >> g[i][j];
        }
    }
    
    using Pair = tuple<ll,int>;
    priority_queue<Pair, vector<Pair>, greater<Pair>> pq;
    pq.push({0, 0});

    vector<ll> min_car(n, 1e18);
    min_car[0] = 0;

    while(!pq.empty()) {
        auto [cost, v] = pq.top();
        pq.pop();

        if (cost > min_car[v]) continue;

        for (int nv: seq(n)) {
            if (nv == v) continue;

            auto nc = min_car[v] + g[v][nv]*a;
            if (min_car[nv] > nc) {
                min_car[nv] = nc;
                pq.push({min_car[nv], nv});
            }
        }
    }
    
    pq.push({0, n-1});

    vector<ll> min_train(n, 1e18);
    min_train[n-1] = 0;

    while(!pq.empty()) {
        auto [cost, v] = pq.top();
        pq.pop();

        if (cost > min_train[v]) continue;

        for (int nv: seq(n)) {
            if (nv == v) continue;

            auto nc = min_train[v] + g[v][nv]*b+c;
            if (min_train[nv] > nc) {
                min_train[nv] = nc;
                pq.push({min_train[nv], nv});
            }
        }
    }
    
    ll result = 1e18;
    for (int i: seq(n)) {
        result = min(result, min_car[i]+min_train[i]);
    }
    cout << result;
    return 0;
}
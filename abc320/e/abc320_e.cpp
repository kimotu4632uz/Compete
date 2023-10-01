#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr auto seq(int begin, int end) { return ranges::iota_view(begin, end); }
constexpr auto seq(int end) { return ranges::iota_view(0, end); }
#define all(v) v.begin(), v.end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n,m; cin >> n >> m;
    vector<tuple<ll,ll,ll>> ev(m);
    for (auto& [t,w,s]: ev) {
        cin >> t >> w >> s;
    }

    vector<ll> eat(n,0);

    using timet = tuple<ll,int>;
    auto comp = [](timet a, timet b) {
        auto [ax,ay] = a; auto [bx,by]=b;
        return ax > bx;
    };
    priority_queue<timet, vector<timet>, decltype(comp)> time;
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i: seq(n)) q.push(i);

    for (auto&& [t,w,s]: ev) {
        while (!time.empty()) {
            auto [bt,u] = time.top();
            if (bt <= t) {
                q.push(u);
                time.pop();
            } else {
                break;
            }
        }

        if (!q.empty()){
            int u = q.top();
            eat[u] += w;
            time.push({t+s, u});
            q.pop();
        }
    }

    for (auto e: eat) cout << e << endl;

    return 0;
}
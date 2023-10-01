#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr auto seq(int begin, int end) { return ranges::iota_view(begin, end); }
constexpr auto seq(int end) { return ranges::iota_view(0, end); }
#define all(v) v.begin(), v.end()

using Graph = vector<vector<tuple<int,ll,ll>>>;

vector<bool> seen;
vector<optional<tuple<ll,ll>>> pos;
void dfs(Graph& g, int v) {
    seen[v] = true;

    for (auto&& [nv, dx, dy] : g[v]) {
        if (seen[nv]) continue;
        if (pos[v]) {
            auto [x,y] = pos[v].value();
            pos[nv] = {x+dx, y+dy};
        }
        dfs(g, nv);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;
    Graph g(n);

    for (int i: seq(m)) {
        int a,b;
        ll x,y;
        cin >> a >> b >> x >> y;
        --a; --b;
        g[a].push_back({b,x,y});
        g[b].push_back({a,-1*x,-1*y});
    }

    seen.assign(n, false);
    pos.assign(n, nullopt);
    pos[0] = {0,0};
    dfs(g, 0);

    for (auto&& e: pos) {
        if (e) {
            auto [x,y] = e.value();
            cout << x << ' ' << y << endl;
        } else {
            cout << "undecidable" << endl;
        }
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr auto seq(int begin, int end) { return ranges::iota_view(begin, end); }
constexpr auto seq(int end) { return ranges::iota_view(0, end); }
#define all(v) std::ranges::begin((v)), std::ranges::end((v))

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;
    vector<int> a(m), b(m);
    for (int i: seq(m)) {
        int t; cin >> t; --t;
        a[i] = t;
    }
    for (int i: seq(m)) {
        int t; cin >> t; --t;
        b[i] = t;
    }

    vector g(n, vector<int>());
    for (int i: seq(m)) {
        g[a[i]].push_back(b[i]);
        g[b[i]].push_back(a[i]);
    }


    map<int, int> spin;
    queue<int> q;

    for (int i: seq(n)) {
        if (spin.contains(i)) continue;
        spin[i] = -1;
        q.push(i);
    
        while (!q.empty()) {
            int v = q.front();
            q.pop();
    
            for (auto&& nv: g[v]) {
                if (spin.contains(nv)) {
                    if (spin[nv] == spin[v]) {
                        cout << "No";
                        return 0;
                    }
                } else {
                    spin[nv] = spin[v] * -1;
                    q.push(nv);
                }
            }
        }
    }

    cout << "Yes";
    return 0;
}
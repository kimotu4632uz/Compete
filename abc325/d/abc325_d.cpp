#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr auto seq(int begin, int end) { return ranges::iota_view(begin, end); }
constexpr auto seq(int end) { return ranges::iota_view(0, end); }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<pair<ll,ll>> td(n);
    for (auto& [t,d]: td) cin >> t >> d;

    ranges::sort(td);
    queue<pair<ll,ll>> q;
    for (auto&& e: td) q.push(e);
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    int ans = 0;
    ll now=1;
    while(true) {
        while (!q.empty()) {
            auto&& [t,d] = q.front();
            if (t == now) {
                pq.push(now+d);
                q.pop();
            }
            else break;
        }

        while (!pq.empty()) {
            auto end = pq.top();
            pq.pop();
            if (now <= end) {
                ++ans; ++now;
                break;
            }
        }

        if (q.empty() && pq.empty()) break;
        if (pq.empty()) now = q.front().first;
    }

    cout << ans;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr auto seq(int begin, int end) { return ranges::iota_view(begin, end); }
constexpr auto seq(int end) { return ranges::iota_view(0, end); }
#define all(v) std::ranges::begin((v)), std::ranges::end((v))

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    set<int> a;
    priority_queue<int> pq;
    for (int i: seq(n)) {
        int t; cin >> t;
        a.insert(t);
    }
    for (auto&& e: a) pq.push(e);
    pq.pop();
    cout << pq.top();
    return 0;
}
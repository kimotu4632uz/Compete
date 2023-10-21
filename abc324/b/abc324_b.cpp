#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr auto seq(int begin, int end) { return ranges::iota_view(begin, end); }
constexpr auto seq(int end) { return ranges::iota_view(0, end); }
#define all(v) v.begin(), v.end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n; cin >> n;
    vector<ll> pow3s;
    pow3s.push_back(1);
    for (int i: seq(37)) {
        pow3s.push_back(pow3s.back() * 3);
    }

    ll a = 1;
    for (int i: seq(60)) {
        if (n % a == 0) {
            if (binary_search(all(pow3s), n/a)) {
                cout << "Yes";
                return 0;
            }
        }
        a *= 2;
    }
    cout << "No";
    return 0;
}
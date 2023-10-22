#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr auto seq(int begin, int end) { return ranges::iota_view(begin, end); }
constexpr auto seq(int end) { return ranges::iota_view(0, end); }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<int> a(n);
    
    for (int i: seq(n)) {
        int t; cin >> t;
        a[i] = t-1;
    }
    
    vector<ll> left(n,0), right(n,0);
    ++left[a[0]];
    for (int i: seq(2, n)) {
        ++right[a[i]];
    }
    
    ll sum = 0;
    for (int i: seq(n)) sum += (left[i] * right[i]);

    ll ans = 0;
    for (int j: seq(1, n-1)) {
        ans += (sum - (left[a[j]] * right[a[j]]));
        
        if (a[j] != a[j+1]) {
            sum += right[a[j]];
            sum -= left[a[j+1]];
        } else {
            sum += (right[a[j+1]] - left[a[j]] - 1);
        }
        ++left[a[j]]; --right[a[j+1]];
    }
    
    cout << ans;
    return 0;
}
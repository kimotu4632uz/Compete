#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr auto seq(int begin, int end) { return ranges::iota_view(begin, end); }
constexpr auto seq(int end) { return ranges::iota_view(0, end); }
#define all(v) v.begin(), v.end()

long long pow(int x, int y) {
    long long res = 1;
    for (int i=0;i<y;++i) res *= x;
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    string s; cin >> s;

    vector<int> sn(10,0);
    for (auto&& c: s) {
        ++sn[c - '0'];
    }
    
    ll maxval = pow(10,n);
    
    ll res = 0;
    vector<int> an(10,0);
    for (ll i=0;i*i < maxval;++i) {
        ll val = i*i;
        int sum = 1;
        an.assign(10,0);
        while (true) {
            an[val%10] += 1;
            if (val == (val%10)) break;
            val /= 10;
            ++sum;
        }
        if (sum < n) an[0] += n-sum;
        
        bool flag = true;
        for (int j: seq(1,10)) {
            if (an[j] != sn[j]) flag = false;
        }
        if (flag) ++res;
    }

    cout << res;
    return 0;
}
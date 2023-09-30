#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define irep(i, n) for (int i = (n-1); i >= 0; --i)
#define all(v) v.begin(), v.end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll k; cin >> k;

    ll sb = 0;
    ll sum = 9;
    int r=1;
    vector<ll> v(9); iota(all(v),1);
    vector<ll> vv(9); iota(all(v),1);
    while(true) {
        if (k <= sum) break;
        else {
            sb=sum;
            rep(i,9) sum+=vv[i];
            rep(i,9) vv[i] *= v[i];
            ++r;
        }
    }

9 1+2+...+9 1+4+9+...+81

100
200
210
220
221

    vector<int> ans;
    ans.push_back(10);
    int lst = 0;
    rep(i,k) {
        if (ans.back()-1 > lst) ++lst;
        else {
            if (ans.back() >= 9) {
                ans.back() = 0;
                ans.push_back(1);
            } else ans.back()++;
            lst=0;
        }
    }
    ans[0]=lst;

    irep(i,ans.size()) cout << ans[i];

    return 0;
}
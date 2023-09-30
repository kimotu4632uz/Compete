#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define irep(i, n) for (int i = (n-1); i >= 0; --i)
#define all(v) v.begin(), v.end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;

    vector<int> js;
    for (int i=1;i<10;i++) if (n%i == 0) js.push_back(i);

    rep(i,n+1) {
        bool found=false;
        for (auto&& j : js) if (i%(n/j)==0) { 
            cout << j;
            found=true;
            break;
        }
        if (!found) cout << '-';
    }

    return 0;
}
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
    string s = to_string(n);
    if (s.size() == 1) {
        cout << "Yes";
    } else {
        rep(i,s.size()-1) {
            if (s[i]-'0' <= s[i+1]-'0') {
                cout << "No";
                return 0;
            }
        }
        cout << "Yes";
    }
    return 0;
}
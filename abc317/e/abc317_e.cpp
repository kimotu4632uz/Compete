#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int h, w;
    cin >> h >> w;
    vector<vector<char>> a(h, vector<char>(w));
    tuple<int,int> s, g;
    rep(i, h) {
        rep(j, w) {
            char c;
            cin >> c;
            if (c == 'S') s = {i, j};
            else if (c == 'G') g = {i, j};
            a[i][j] = c;
        }
    }

    rep(i, h) {
        rep(j, w) {
            if (a[i][j] == '>') {
            }
        }
    }
    return 0;
}
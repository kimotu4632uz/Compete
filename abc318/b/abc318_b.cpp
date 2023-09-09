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
    vector<tuple<int,int,int,int>> rect(n);
    rep(i,n) {
        int x1,x2,y1,y2;
        cin >> x1 >> x2 >> y1 >> y2;
        rect[i] = {x1,x2,y1,y2};
    }

    vector<vector<int>> mesh(101, vector<int>(101, 0));
    ll result = 0;
    rep(i, n) {
        auto [x1,x2,y1,y2] = rect[i];
        for (int x=x1; x<x2; ++x) {
            for (int y=y1; y<y2; ++y) {
                if (mesh[x][y] == 0) {
                    ++result;
                    mesh[x][y] = 1;
                }
            }
        }
    }
    cout <<result;
    return 0;
}
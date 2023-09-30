#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define irep(i, n) for (int i = (n-1); i >= 0; --i)
#define all(v) v.begin(), v.end()

int toe(int i, int j) {
    return i*3+j;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    vector<vector<int>> m(3, vector<int>(3));
    rep(i,3) rep(j,3) cin >> m[i][j];

    vector<tuple<int,int,int>> pat;
    for (int j=0;j<3;j++)
        if (m[0][j] == m[1][j]) pat.push_back({toe(0,j), toe(1,j), toe(2,j)});
    for (int j=2;j>=0;j--)
        if (m[2][j] == m[1][j]) pat.push_back({toe(2,j), toe(1,j), toe(0,j)});
    for (int i=0;i<3;i++)
        if (m[i][0] == m[i][1]) pat.push_back({toe(i,0), toe(i,1), toe(i,2)});
    for (int i=2;i>=0;i--)
        if (m[i][2] == m[i][1]) pat.push_back({toe(i,2), toe(i,1), toe(i,0)});
    if (m[0][0] == m[1][1]) pat.push_back({toe(0,0), toe(1,1), toe(2,2)});
    if (m[2][2] == m[1][1]) pat.push_back({toe(2,2), toe(1,1), toe(0,0)});
    if (m[2][0] == m[1][1]) pat.push_back({toe(2,0), toe(1,1), toe(0,2)});
    if (m[0][2] == m[1][1]) pat.push_back({toe(0,2), toe(1,1), toe(2,0)});

    vector<int> v(9);
    iota(all(v), 0);

    ll all=0, gt=0;
    do {
        bool bad = false;
        for (auto&& p : pat) {
            auto [a,b,c] = p;
            int ai,bi,ci;
            rep(i,9) {
                if (v[i] == a) ai=i;
                else if (v[i] == b) bi=i;
                else if (v[i] == c) ci=i;
            }
            if (ai < bi && bi < ci) {
                bad = true;
                break;
            }
        }
        if (!bad) ++gt;
        ++all;

    } while(next_permutation(all(v)));

    cout << (double)gt/all;
    return 0;
}
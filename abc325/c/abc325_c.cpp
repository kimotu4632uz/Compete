#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr auto seq(int begin, int end) { return ranges::iota_view(begin, end); }
constexpr auto seq(int end) { return ranges::iota_view(0, end); }


vector<bool> seen;

vector<tuple<int,int>> d = {{1,1}, {-1,1}, {1,-1}, {-1,-1}, {0,1}, {1,0}, {-1,0}, {0,-1}};
int h, w;

void dfs(vector<vector<int>> &g, int i, int j) {
    seen[g[i][j]] = true;

    for (auto&& [di, dj]: d) {
        int ni = i + di, nj = j+dj;
        if (ni >= 0 && ni < h && nj >= 0 && nj < w) {
            if (g[ni][nj] > 0 && !seen[g[ni][nj]]) {
                seen[g[ni][nj]] = true;

                dfs(g, ni, nj);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> h >> w;
    vector sv(h, vector(w, 0));
    int count = 1;
    for (int i: seq(h)) {
        string s; cin >> s;
        for (int j: seq(w)) {
            if (s[j] == '#') {
                sv[i][j] = count;
                ++count;
            }
        }
    }
    
    seen.assign(count, false);
    int ans = 0;

    for (int i: seq(h)) {
        for (int j: seq(w)) {
            if (sv[i][j] > 0 && !seen[sv[i][j]]) {
                dfs(sv, i, j);
                ++ans;
            }
        }
    }
    cout << ans;
    return 0;
}
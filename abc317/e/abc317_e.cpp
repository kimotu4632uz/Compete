#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr auto seq(int begin, int end) { return ranges::iota_view(begin, end); }
constexpr auto seq(int end) { return ranges::iota_view(0, end); }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int h, w;
    cin >> h >> w;
    vector<vector<char>> a(h, vector<char>(w));
    for (int i: seq(h)) {
        for (int j: seq(w)) {
            char c; cin >> c;
            a[i][j] = c;
        }
    }

    string arrow = "^v><";
    set<char> def = {'#', '^', 'v', '>', '<'};
    vector<tuple<int,int>> d = {{-1,0}, {1,0}, {0,1}, {0,-1}};
    
    pair<int,int> start, goal;
    vector avail(h, vector<bool>(w, true));
    
    auto in = [&](int i, int j) {
        return 0 <= i && i < h && 0 <= j && j < w;
    };
    
    for (int i: seq(h)) {
        for (int j: seq(w)) {
            if (a[i][j] == 'S') start = {i,j};
            else if (a[i][j] == 'G') goal = {i,j};
            else if (a[i][j] == '#') avail[i][j] = false;
            else if (auto it = arrow.find(a[i][j]); it != string::npos) {
                auto&& [di, dj] = d[it];

                for (int ni=i+di, nj=j+dj; in(ni,nj) && !def.contains(a[ni][nj]); ni+=di, nj+=dj) {
                    avail[ni][nj] = false;
                }
                avail[i][j] = false;
            }
        }
    }
    
    vector dist(h, vector<int>(w, -1));
    queue<pair<int,int>> q;

    dist[start.first][start.second] = 0;
    q.push(start);

    while (!q.empty()) {
        auto&& [i,j] = q.front();
        q.pop();

        for (auto&& [di, dj]: d) {
            int ni=i+di, nj=j+dj;

            if (!in(ni,nj)) continue;
            if (dist[ni][nj] != -1) continue;
            if (!avail[ni][nj]) continue;

            dist[ni][nj] = dist[i][j] + 1;
            q.push({ni,nj});
        }
    }

    cout << dist[goal.first][goal.second];
    return 0;
}
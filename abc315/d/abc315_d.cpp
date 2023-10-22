#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr auto seq(int begin, int end) { return ranges::iota_view(begin, end); }
constexpr auto seq(int end) { return ranges::iota_view(0, end); }

int find_nonzero(vector<int> &v) {
    int count = 0;
    int ans = -1;
    for (int i: seq(26)) {
        if (v[i] > 0) {
            ++count;
            ans = i;
        }
    }
    if (count > 1) {
        return -1;
    } else {
        return ans;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int h, w; cin >> h >> w;
    vector row(h, vector<int>(26,0)); 
    vector col(w, vector<int>(26,0)); 
    vector<bool> aliverow(h, true), alivecol(w, true);
    
    for (int i: seq(h)) {
        string s; cin >> s;
        for (int j: seq(w)) {
            int c = s[j] - 'a';
            ++row[i][c];
            ++col[j][c];
        }
    }
    
    while(true) {
        vector<pair<int,int>> remove_row;
        for (int i: seq(h)) {
            if (aliverow[i]) {
                int key = find_nonzero(row[i]);
                if (key != -1 && row[i][key] > 1) {
                    remove_row.push_back({i, key});
                }
            }
        }

        vector<pair<int,int>> remove_col;
        for (int i: seq(w)) {
            if (alivecol[i]) {
                int key = find_nonzero(col[i]);
                if (key != -1 && col[i][key] > 1) {
                    remove_col.push_back({i, key});
                }
            }
        }
 
        if (remove_row.empty() && remove_col.empty()) break;

        for (auto&& [i, c]: remove_row) {
            aliverow[i] = false;
            for (int j: seq(w)) {
                col[j][c] = max(0, col[j][c]-1);
            }
        }
        for (auto&& [i, c]: remove_col) {
            alivecol[i] = false;
            for (int j: seq(h)) {
                row[j][c] = max(0, row[j][c]-1);
            }
        }
    }
    
    cout << ranges::count(aliverow, true) * ranges::count(alivecol, true);
    return 0;
}
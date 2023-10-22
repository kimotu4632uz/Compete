#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr auto seq(int begin, int end) { return ranges::iota_view(begin, end); }
constexpr auto seq(int end) { return ranges::iota_view(0, end); }


tuple<int,int,int> find_dual(vector<int> &v, vector<int> &idx) {
    if (v[idx[0]] == v[idx[1]]) return {idx[0], idx[1], idx[2]};
    else if (v[idx[0]] == v[idx[2]]) return {idx[0], idx[2], idx[1]};
    else if (v[idx[2]] == v[idx[1]]) return {idx[2], idx[1], idx[0]};
    else return {-1,-1,-1};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    vector<int> m(9);
    for (int i: seq(9)) {
        cin >> m[i];
    }

    vector<vector<int>> idxs = {{0,1,2}, {3,4,5}, {6,7,8}, {0,3,6}, {1,4,7}, {2,5,8}, {0,4,8}, {2,4,6}};
    vector<tuple<int,int,int>> pat;
    for (auto&& idx: idxs) {
        auto [a,b,c] = find_dual(m, idx);
        if (a != -1) {
            pat.push_back({a,b,c});
        }
    }

    vector<int> v(9);
    iota(v.begin(), v.end(), 0);

    ll all=0, gt=0;
    do {
        bool bad = false;
        for (auto&& [a,b,c] : pat) {
            int ai, bi, ci;
            for (int i: seq(9)) {
                if (v[i] == a) ai = i;
                if (v[i] == b) bi = i;
                if (v[i] == c) ci = i;
            }
            if (ai < ci && bi < ci) bad = true;
        }
        if (!bad) ++gt;
        ++all;

    } while(ranges::next_permutation(v).found);

    cout << fixed << setprecision(15) << (double)gt/all;
    return 0;
}
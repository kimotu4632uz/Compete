#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr auto seq(int begin, int end) { return ranges::iota_view(begin, end); }
constexpr auto seq(int end) { return ranges::iota_view(0, end); }
#define all(v) std::ranges::begin((v)), std::ranges::end((v))

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, q; cin >> n >> q;
    vector<int> c(n);
    for (int i: seq(n)) {
        int t; cin >> t;
        c[i] = t-1;
    }

    vector<pair<int,int>> query(q);
    for (int i: seq(q)) {
        int a,b; cin >> a >> b;
        query[i] = {a-1,b-1};
    }

    vector box(n, set<int>());
    for (int i: seq(n)) {
        box[i].insert(c[i]);
    }

    for (auto [a,b]: query) {
        if (box[a].size() > box[b].size()) {
            for (int color: box[b]) {
                box[a].insert(color);
            }
            box[b].clear();
            swap(box[a], box[b]);
        } else {
            for (int color: box[a]) {
                box[b].insert(color);
            }
            box[a].clear();
        }
        cout << box[b].size() << endl;
    }

    return 0;
}
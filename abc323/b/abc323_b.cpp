#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr auto seq(int begin, int end) { return ranges::iota_view(begin, end); }
constexpr auto seq(int end) { return ranges::iota_view(0, end); }
#define all(v) v.begin(), v.end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;

    vector<tuple<int,int>> sc(n);

    for (int i: seq(n)) {
        string s; cin >> s;
        int score = 0;
        for (auto&& c: s) {
            if (c == 'o') ++score;
        }
        sc[i] = {score, i+1};
    }
    
    sort(all(sc), [](tuple<int,int> a, tuple<int,int> b) {
        auto [aa, ab] = a; auto [ba, bb] = b;
        if (aa != ba) return aa > ba;
        else return ab < bb;
    });
    
    for (auto&& [a,b]: sc) cout << b << ' ';

    return 0;
}
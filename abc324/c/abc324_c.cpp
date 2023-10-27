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
    string t; cin >> t;
    vector<string> ss(n);
    for (auto& s: ss) cin >> s;

    vector<int> result;
    for (int i: seq(n)) {
        auto ts = t.size(), sis = ss[i].size();
        auto mins = min(ts, sis);
        
        if (ts > sis+1 || sis > ts+1) continue;

        int first = 0, last = 0;
        for (int j: seq(mins)) {
            if (ss[i][j] == t[j]) ++first;
            else break;
        }
        for (int j: seq(mins)) {
            if (ss[i][sis-j-1] == t[ts-j-1]) ++last;
            else break;
        }

        if (ts == sis) {
            if (first == ts) result.push_back(i+1);
            else if (first + last + 1 == ts) result.push_back(i+1);
        } else {
            if (first + last >= mins) result.push_back(i+1);
        }
    }
    
    cout << result.size() << endl;
    for (auto i: result) cout << i << ' ';
    return 0;
}
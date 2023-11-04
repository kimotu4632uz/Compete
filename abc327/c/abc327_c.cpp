#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr auto seq(int begin, int end) { return ranges::iota_view(begin, end); }
constexpr auto seq(int end) { return ranges::iota_view(0, end); }
#define all(v) std::ranges::begin((v)), std::ranges::end((v))

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    vector row(9, vector<int>(9,0));
    vector col(9, vector<int>(9,0));
    vector grid(3, vector(3, vector<int>(9,0)));

    for (int i: seq(9)) {
        for (int j: seq(9)) {
            int a; cin >> a; --a;
            row[i][a]++;
            col[j][a]++;
            grid[i/3][j/3][a]++;
        }
    }

    for (int i: seq(9)) {
        bool flag = ranges::all_of(row[i], [](int x){ return  x == 1;});
        if (!flag) {
            cout << "No";
            return 0;
        }
    }
    for (int i: seq(9)) {
        bool flag = ranges::all_of(col[i], [](int x){ return  x == 1;});
        if (!flag) {
            cout << "No";
            return 0;
        }
    }
 
    for (int i: seq(3)) {
        for (int j: seq(3)) {
            bool flag = ranges::all_of(grid[i][j], [](int x) {return x == 1;});
            if (!flag) {
                cout << "No";
                return 0;
            }
        }
    }
    cout << "Yes";
    return 0;
}
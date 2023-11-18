#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr auto seq(int begin, int end) { return ranges::iota_view(begin, end); }
constexpr auto seq(int end) { return ranges::iota_view(0, end); }
#define all(v) std::ranges::begin((v)), std::ranges::end((v))

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<int> d(n+1);
    for (int i: seq(1,n+1)) cin >> d[i];

    set<int> zoro2 = {11,22,33,44,55,66,77,88,99};
    int result = 0;
    for (int i: seq(1,n+1)) {
        if (i < 10) {
            if (i <= d[i]) result++;
            if (10*i+i <= d[i]) result++;
        } else if (zoro2.contains(i)) {
            if (i <= d[i]) result++;
            if (i%10 <= d[i]) result++;
        }
    }

    cout << result;
    return 0;
}
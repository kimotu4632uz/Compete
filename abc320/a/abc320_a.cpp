#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr auto iv(int begin, int end) { return ranges::iota_view(begin, end); }
constexpr auto iv(int end) { return ranges::iota_view(0, end); }
#define all(v) v.begin(), v.end()

long long pow(int x, int y) {
    int res = 1;
    for (int i=0;i<y;++i) res *= x;
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int a, b; cin >> a >> b;
    cout << pow(a,b)+pow(b,a);

    return 0;
}
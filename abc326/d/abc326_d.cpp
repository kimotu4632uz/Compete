#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr auto seq(int begin, int end) { return ranges::iota_view(begin, end); }
constexpr auto seq(int end) { return ranges::iota_view(0, end); }
#define all(v) std::ranges::begin((v)), std::ranges::end((v))

int fromN(vector<int> from, int base) {
    long long sum = 0;
    for (int n : from) {
        sum = sum * base + n;
    }
    return sum;
}

vector<int> toN(int dec, int base, int pad=0) {
    vector<int> res;
    do {
        int num = dec % base;
        res.push_back(num);
        dec /= base;
    } while (dec);
    if (pad != 0) res.resize(pad, 0);
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    string r,c; cin >> r >> c;

    string s = "ABC";
    for (int i: seq(n-3)) s += '.';

    vector<vector<string>> row(3);
    do {
        char first = *ranges::find_if(s, [](char& c){ return c != '.'; });
        row[first - 'A'].push_back(s);
    } while(ranges::next_permutation(s).found);

    return 0;
}
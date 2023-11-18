#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr auto seq(int begin, int end) { return ranges::iota_view(begin, end); }
constexpr auto seq(int end) { return ranges::iota_view(0, end); }
#define all(v) std::ranges::begin((v)), std::ranges::end((v))

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;
    vector<int> a(m);
    for (int i: seq(m)) {
        int t; cin >> t; --t;
        a[i] = t;
    }

    vector<int> res(n, 0);
    res[a[0]] = 1;
    int maxnum = 1;
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(a[0]);
    cout << a[0]+1 << endl;

    for (int i: seq(1,m)) {
        int num = res[a[i]];
        res[a[i]]++;

        if (num == maxnum) {
            cout << a[i]+1 << endl;
            maxnum = num+1;
            priority_queue<int, vector<int>, greater<int>>().swap(pq);
            pq.push(a[i]);
        } else if (num +1 == maxnum) {
            pq.push(a[i]);
            cout << pq.top()+1 << endl;
        } else {
            cout << pq.top()+1 << endl;
        }
    }
    return 0;
}
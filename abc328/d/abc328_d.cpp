#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr auto seq(int begin, int end) { return ranges::iota_view(begin, end); }
constexpr auto seq(int end) { return ranges::iota_view(0, end); }
#define all(v) std::ranges::begin((v)), std::ranges::end((v))

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s; cin >> s;
    stack<char> st;
    for (int i: seq(s.size())) {
        if (st.size() >= 2) {
            char b = st.top();
            st.pop();
            char a = st.top();

            if (a == 'A' && b == 'B' && s[i] == 'C') {
                st.pop();
            } else {
                st.push(b); st.push(s[i]);
            }
        } else {
            st.push(s[i]);
        }
   }

    vector<char> result;
    while (!st.empty()) {
        result.push_back(st.top());
        st.pop();
    }
    for (char c: result | views::reverse) {
        cout << c;
    }
    return 0;
}
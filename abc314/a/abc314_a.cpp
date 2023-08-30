#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string pi_u = "1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679";
    int n;

    cin >> n;
    cout << "3." << pi_u.substr(0, n) << endl;

    return 0;
}
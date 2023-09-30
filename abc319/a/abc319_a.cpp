#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define irep(i, n) for (int i = (n-1); i >= 0; --i)
#define all(v) v.begin(), v.end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    unordered_map<string, int> map{
{"tourist", 3858},
{"ksun48", 3679},
{"Benq",   3658},
{"Um_nik", 3648},
{"apiad", 3638},
{"Stonefeang", 3630},
{"ecnerwala", 3613},
{"mnbvmar", 3555},
{"newbiedmy", 3516},
{"semiexp", 3481}
    };

    string key;
    cin >> key;
    cout << map.at(key);

    return 0;
}
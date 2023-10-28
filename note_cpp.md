# 数値関係
## 指数形式
```
1200 = 1.2e3
```
のように10のn乗で表記する方法  
```
10^N = 1eN
```
となる


## intの最大値
- int : **10^9**
- longlong : 10^19


## 小数点出力
`d`をdoubleとして小数点以下15桁で出力  
```
cout << fixed << setprecision(15) << d
```
デフォでは5桁なので注意


# 文字列処理
- 大文字に
    ```
    ranges::transform(str, str.begin(), ::toupper);
    ```

- 小文字に
    ```
    ranges::transform(str, str.begin(), ::tolower);
    ```


# vector
## 初期化
- 要素数指定
    ```
    vector<int> a(n);
    ```
    ここで`push_back`すると`n+1`番目に追加される

- 要素数+初期値指定
    ```
    vector<int> a(n, 0);
    ```
    全て`0`で初期値される

- リサイズ
    - resize
        ```
        a.resize(n, v);
        ```
        サイズ`n`にリサイズし，伸びた部分には`v`が入る  
        第二引数は省略可
    
    - assign
        ```
        a.resize(n, v);
        ```
        サイズ`n`にリサイズし，要素すべてを`v`にする  


# 数列を作りたい
```
iota(a.begin(), a.end(), 0)
```
`next_permutation`と合わせて使う  
- [c++23でrangesに入るらしい](https://cpprefjp.github.io/reference/numeric/ranges_iota.html)


# 競プロ特有？
- 数値をcharからintに
    ```
    c - '0'
    ```

- アルファベットをcharではなくintで管理したい
    ```
    c - 'a'
    ```

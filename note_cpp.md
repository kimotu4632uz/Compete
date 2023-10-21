- vector内でi以上の最初の値がほしい
    - 二分探索 -> lower_bound

- priority_queue: [リファレンス](https://cpprefjp.github.io/reference/queue/queue.html)

# 文字列処理
- 大文字に
```
ranges::transform(str, str.begin(), ::toupper);
```

- 小文字に
```
ranges::transform(str, str.begin(), ::tolower);
```
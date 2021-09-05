#![allow(unused_imports)]
use proconio::{fastout, input};
use proconio::marker::Chars;

macro_rules! nested_vec {
  ($e:expr; $n:expr) => {
    vec![$e; $n]
  };
  ($e:expr; $n:expr $(; $m:expr)+) => {
    vec![nested_vec!($e $(; $m)+); $n]
  };
}

#[fastout]
fn main() {
  input! {
    n: usize,
    s: Chars,
  }

  let mut dp = nested_vec![0; n; 1 << 10; 10];

  let ascii_a = 'A' as i32;
  let modu = 998244353;

  for i in 0..n {
    let c = s[i] as i32 - ascii_a;
    dp[i][1 << c][c as usize] = 1;
  }

  for i in 0..(n-1) {
    for u in 0..(1 << 10) {
      for last in 0..10 {
        dp[i+1][u][last] += dp[i][u][last];
        dp[i+1][u][last] %= modu; 

        let c = s[i] as i32 - ascii_a;
        if (u >> c) & 1 == 1 && c as usize != last {
          continue;
        }
        dp[i+1][u | (1 << c)][c as usize] += dp[i][u][last];
        dp[i+1][u | (1 << c)][c as usize] %= modu;
      }
    }
  }

  let mut result = 0;

  for u in 0..(1 << 10) {
    for last in 0..10 {
      result += dp[n-1][u][last];
      result %= modu;
    }
  }

  println!("{}", result);
}

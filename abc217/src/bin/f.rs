#![allow(unused_imports)]
use proconio::{input, fastout};

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
    m: i32,
    ab: [(usize, usize); m]
  }

  const MOD: i64 = 998244353;

  let mut f = nested_vec![false; 2*n + 1; 2*n + 1];
  for (a, b) in ab {
    f[a][b] = true;
    f[b][a] = true;
  }

  let mut c = nested_vec![0i64; n+1; n+1];
  c[0][0] = 1;
  for i in 1..=n {
    c[i][0] = 1;
    c[i][i] = 1;
    for j in 1..=(i-1) {
      c[i][j] = (c[i-1][j-1] + c[i-1][j]) % MOD;
    }
  }

  let mut dp = nested_vec![0i64; 2*n + 1; n+1];
  for i in 0..=2*n {
    dp[i][0] = 1;
  }

  for j in 1..=n {
    for i in 0..=2*(n - j) {
      for k in (1..=j).filter(|k| f[i+1][i + 2*k]) {
        let x: i64 = (dp[i+1][k-1] * dp[i + 2*k][j-k]) % MOD;
        dp[i][j] = (x * c[j][k] + dp[i][j]) % MOD;
      }
    }
  }

  println!("{}", dp[0][n]);
}

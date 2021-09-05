#![allow(unused_imports)]
use proconio::{fastout, input};

#[fastout]
fn main() {
  input! {
    n: i64,
  }

  let mut ke = 1;
  for i in 1..63 {
    ke *= 2;
    if ke > n {
      println!("{}", i-1);
      return;
    }
  }
}

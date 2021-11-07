#![allow(unused_imports)]
use proconio::{input, fastout};
use proconio::marker::Chars;

#[fastout]
fn main() {
  input! {
    n: usize,
    s: Chars
  }

  if s[n-1] == 'o' {
    println!("Yes");
  } else {
    println!("No");
  }
}

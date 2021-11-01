#![allow(unused_imports)]
use proconio::{input, fastout};
use proconio::marker::Chars;

#[fastout]
fn main() {
  input! {
    s: Chars,
    t: Chars
  }

  for i in 0..s.len() {
    if t.len() < i+1 {
      println!("No");
      return;
    }

    if s[i] == t[i] {
      continue;
    } else if s[i] < t[i] {
      println!("Yes");
      return;
    } else {
      println!("No");
      return;
    }
  }

  println!("Yes");
}

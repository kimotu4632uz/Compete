#![allow(unused_imports)]
use proconio::{fastout, input};
use proconio::marker::Chars;
use permutohedron::LexicalPermutation;

#[fastout]
fn main() {
  input! {
    mut s: Chars,
    k: i32,
  }

  s.sort();

  for _ in 0..(k-1) {
    s.next_permutation();
  }

  println!("{}", s.iter().collect::<String>());
}

#![allow(unused_imports)]
use proconio::{input, fastout};
use std::char;

#[fastout]
fn main() {
  input! {
    p: [u32; 26]
  }

  let a = 'a' as u32 - 1;

  let result: String = p.into_iter().map(|x| char::from_u32(a+x).unwrap()).collect();
  println!("{}", result);
}

#![allow(unused_imports)]
use proconio::{input, fastout};
use std::collections::HashMap;
use maplit::hashset;

#[fastout]
fn main() {
  input! {
    s1: String,
    s2: String,
    s3: String
  }

  let list = hashset!{s1, s2, s3};

  for s in &["ABC".to_string(), "ARC".to_string(), "AGC".to_string(), "AHC".to_string()] {
    if !list.contains(s) {
      println!("{}", s);
      return;
    }
  }
}

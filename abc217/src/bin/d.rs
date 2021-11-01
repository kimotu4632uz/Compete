#![allow(unused_imports)]
use proconio::{input, fastout};
use std::collections::BTreeSet;
use maplit::btreeset;

#[fastout]
fn main() {
  input! {
    l: i64,
    q: i32,
    cx: [(i32, i64); q],
  }

  let mut tree = btreeset!{0, l};

  for (c, x) in cx {
    if c == 1 {
      tree.insert(x);
    } else {
      let min = tree.range(..x).last().unwrap();
      let max = tree.range(x..).next().unwrap();
      println!("{}", max - min);
    }
  }
}

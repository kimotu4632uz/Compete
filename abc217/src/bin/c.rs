#![allow(unused_imports)]
use proconio::{input, fastout};

#[fastout]
fn main() {
  input! {
    n: usize,
    p: [i32; n],
  }

  let mut q = vec![String::new(); n];

  for i in 0..n {
    q[p[i] as usize - 1] = (i as i32 + 1).to_string();
  }

  println!("{}", q.join(" "))
}

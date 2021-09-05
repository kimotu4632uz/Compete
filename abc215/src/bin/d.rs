#![allow(unused_imports)]
use proconio::{input, fastout};
use std::collections::HashSet;

fn divvv(n: i32, d: i32) -> i32 {
  if n % d != 0 || n == 1 {
    n
  } else {
    divvv(n/d, d)
  }
}

fn find_p(n: i32, min: i32) -> i32 {
  for i in min..=((n as f32).sqrt().floor() as i32) {
    if n % i == 0 {
      return i;
    }
  }

  return n;
}

fn p_fact(n: i32) -> Vec<i32> {
  let mut result = vec![];
  let mut min = 2;
  let mut n = n;

  while n != 1 {
    let p = find_p(n, min);
    result.push(p);
    min = p + 1;
    n = divvv(n, p);
  }

  return result;
}

#[fastout]
fn main() {
  input! {
    n: i32,
    m: i32,
    aa: [i32; n],
  }

  let mut set: HashSet<_> = (1..=m).collect();
  let mut removed = vec![];

  for a in aa.into_iter().filter(|&x| x != 1) {
    for p in p_fact(a) {
      if !removed.contains(&p) {
        for i in 1..=(m/p) {
          set.remove(&(p*i));
        }
      }
      removed.push(p);
    }
  }

  let mut result: Vec<i32> = set.into_iter().collect();
  result.sort();

  println!("{}", result.len());
  for e in result {
    println!("{}", e);
  }
}

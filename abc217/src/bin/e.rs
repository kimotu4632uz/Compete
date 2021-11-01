#![allow(unused_imports)]
use proconio::{input, fastout};
use std::cmp::Reverse;
use std::collections::{VecDeque, BinaryHeap};

#[fastout]
fn main() {
  input! {
    q: i32,
  }

  let mut query = vec![];

  for _ in 0..q {
    input! {
      c: i32,
    }

    if c == 1 {
      input!{
        x: i64,
      }
      query.push((c, Some(x)))
    } else {
      query.push((c, None))
    }
  }

  let mut heap: BinaryHeap<Reverse<i64>> = BinaryHeap::new();
  let mut queue = VecDeque::new();

  for (o, x) in query {
    if o == 1 {
      queue.push_back(x.unwrap());
    } else if o == 2 {
      if !heap.is_empty() {
        println!("{}", heap.pop().unwrap().0);
      } else {
        println!("{}", queue.pop_front().unwrap());
      }
    } else {
      while !queue.is_empty() {
        heap.push(Reverse(queue.pop_front().unwrap()));
      }
    }
  }
}

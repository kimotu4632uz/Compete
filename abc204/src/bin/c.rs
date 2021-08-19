#![allow(unused_imports)]
use proconio::{fastout, input};
use proconio::marker::Chars;

use std::collections::VecDeque;
use std::collections::HashSet;

#[fastout]
fn main() {
    input! {
        n: i32,
        m: i32,
        a: [(i32, i32); m]
    }

    let (start, _) = a.iter().min_by_key(|(x, _)| x).unwrap();
    let mut set = HashSet::new();
    let mut q = VecDeque::new();
    let mut before = Vec::new();
    before.push(start);

    loop {
        if q.is_empty() { break; }
        else {
            let s = q.pop_front().unwrap();
            let n = a.iter().filter(|(x, _)| x == s);

            for (_, n) in n {
                q.push_back(n);
                before.push(n);
            }
        }
    }
}

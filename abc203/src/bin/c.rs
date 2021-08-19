#![allow(unused_imports)]
use proconio::{fastout, input};
use proconio::marker::Chars;

#[fastout]
fn main() {
    input! {
        n: u32,
        mut k: u64,
        mut f: [(u64, u32); n],
    }

    f.sort();
    let mut p: u64 = 0;

    for (a, b) in f {
        if (a as u64 - p) <= k {
            k -= a as u64 - p;
            k += b as u64;
            p = a as u64;
        } else {
            break;
        }
    }

    println!("{}", p + k);
}

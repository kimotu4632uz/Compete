#![allow(unused_imports)]
use proconio::{fastout, input};
use proconio::marker::Chars;

#[fastout]
fn main() {
    input! {
        n: i32,
        k: i32,
    }

    println!("{}", 50*n*k*(n+1) + n*k*(k+1)/2); // 100 * 1/2 n(n+1) * k + 1/2 k(k+1) * n
}

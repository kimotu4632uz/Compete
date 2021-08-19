#![allow(unused_imports)]
use proconio::{fastout, input};
use proconio::marker::Chars;

#[fastout]
fn main() {
    input! {
        a: i32,
        b: i32,
        c: i32
    }

    if a == b {
        println!("{}", c)
    } else if a == c {
        println!("{}", b)
    } else if b == c {
        println!("{}", a)
    } else {
        println!("0")
    }
}

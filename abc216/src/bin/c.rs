#![allow(unused_imports)]
use proconio::{fastout, input};
use proconio::marker::Chars;

#[fastout]
fn main() {
    input! {
        mut n: u64,
    }

    let mut result = Vec::new();

    loop {
        if n == 0 {
            break;
        }
        if n % 2 == 0 {
            result.push("B");
            n /= 2;
        } else {
            result.push("A");
            n -=1;
        }
    }

    result.reverse();
    println!("{}", result.join(""));
}

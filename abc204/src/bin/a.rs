#![allow(unused_imports)]
use proconio::{fastout, input};
use proconio::marker::Chars;

#[fastout]
fn main() {
    input! {
        x: i32,
        y: i32,
    }

    if (x == 0 && y == 1) || (x == 1 && y == 0) {
        println!("2");
    } else if (x == 0 && y == 2) || (x == 2 && y == 0) {
        println!("1");
    } else if (x == 1 && y == 2) || (x == 2 && y == 1) {
        println!("0");
    } else {
        println!("{}", x);
    }
}

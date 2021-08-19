#![allow(unused_imports)]
use proconio::{fastout, input};
use proconio::marker::Chars;

#[fastout]
fn main() {
    input! {
        n: i32,
        a: [i32; n],
    }

    println!("{}", a.into_iter().map(|x| if x > 10 { x-10 } else { 0 }).sum::<i32>());
}

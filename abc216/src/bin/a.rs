#![allow(unused_imports)]
use proconio::{fastout, input};
use proconio::marker::Chars;

#[fastout]
fn main() {
    input! {
        a: String,
    }

    let xy: Vec<&str> = a.split('.').collect();
    let x: i32 =  xy[0].parse().unwrap();
    let y: i32 =  xy[1].parse().unwrap();

    if 0 <= y && y <= 2 {
        println!("{}-", x);
    } else if 3 <= y && y <= 6 {
        println!("{}", x);
    } else if 7 <= y && y <= 9 {
        println!("{}+", x);
    }
}

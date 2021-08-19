#![allow(unused_imports)]
use proconio::{fastout, input};
use proconio::marker::Chars;

#[fastout]
fn main() {
    input! {
        n: i32,
        mut t: [i32; n]
    }

    let sum: i32 = t.iter().sum::<i32>();
    let ave = sum / 2;
    let mut n = 0i32;

    t.sort();

    for x in t {
        if (n + x) <= ave {
            n += x;
        } else {
            break;
        }
    }

    println!("{}", if sum - n > n { sum - n } else { n });
}

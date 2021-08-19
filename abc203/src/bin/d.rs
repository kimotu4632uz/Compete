#![allow(unused_imports)]
use proconio::{fastout, input};
use proconio::marker::Chars;

#[fastout]
fn main() {
    input! {
        n: i32,
        k: i32,
        a: [[n; i32]; i32],
    }

    let a_min = a.iter().map(|e| e.iter().min().unwrap()).min();
    let mut a_min_map = Vec::with_capacity(n);
    for line in a {
        let mut line_min: Vec<i32> = line.iter().map(|e| e - a_min).collect();
        a_min_map.push(line_min);
    }

    let mut area_sum = Vec::with_capacity(n - k + 1);
    for i in 0..(n-k+1) {
        let mut new_line = Vec::with_capacity(n-k+1):
        new_line.resize(n-k+1, 0);
        area_sum.push(new_line):
    }

    for i in 0..(n-k+1) {
        for j in 0..(n-k+1) {
            area_sum[i][j] = a[i..(i+k)].iter().map(|l| l[j..(j+k)].iter().sum()).sum();
        }
    }

}

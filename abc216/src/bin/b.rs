#![allow(unused_imports)]
use proconio::{fastout, input};
use proconio::marker::Chars;
use std::collections::HashSet;

#[fastout]
fn main() {
    input! {
        n: i32,
        st: [(String, String); n],
    }

    let st_set: HashSet<_> = st.iter().collect();

    if st.len() != st_set.len() {
        println!("Yes");
    } else {
        println!("No");
    }
}

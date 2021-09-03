#![allow(unused_imports)]
use proconio::{fastout, input};
use proconio::marker::Chars;
use std::collections::VecDeque;
use std::collections::HashSet;

#[fastout]
fn main() {
    input! {
        n: usize,
        m: usize,
    }

    let a: Vec<Vec<i32>> = (0..m).map(|_| {
        input!{
            k: i32,
            a: [i32; k],
        }
        return a;
    }).collect();

    let mut queue = VecDeque::new();
    let mut itable: Vec<HashSet<usize>> = Vec::with_capacity(n);
    itable.resize(n, HashSet::new());

    let mut idxs: Vec<i32> = Vec::with_capacity(m);
    idxs.resize(m, 0);

    for i in 0..m {
        let color = a[i][0] as usize - 1;
        itable[color].insert(i);

        if itable[color].len() == 2 {
            queue.push_back((itable[color].clone(), color));
        }
    }

    for _ in 0..n {
        if let Some((color_i, color)) = queue.pop_front() {
            itable[color] = HashSet::new();

            for i in color_i {
                if a[i].len() == (idxs[i] + 1) as usize {
                    idxs[i] = -1;
                } else {
                    idxs[i] += 1;
                    let color = a[i][idxs[i] as usize] as usize - 1;
                    itable[color].insert(i);

                    if itable[color].len() == 2 {
                        queue.push_back((itable[color].clone(), color));
                    }
                }
            }
        } else {
            println!("No");
            return;
        }
    }

    if (0..m).filter(|i| idxs[*i] != -1).count() == 0 {
        println!("Yes");
    } else {
        println!("No");
    }
}

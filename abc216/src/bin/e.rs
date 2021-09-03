#![allow(unused_imports)]
use proconio::{fastout, input};

#[fastout]
fn main() {
    input! {
        n: usize,
        k: i64,
        mut a: [i64; n],
    }

    a.sort_by(|x, y| x.cmp(y).reverse());
    a.push(0);

    let mut sum = 0;
    let mut count = 0;

    for i in 0..n {
        let diff = a[i] - a[i+1];
        let size = i as i64 + 1;

        if (diff * size) + count < k {
            sum += ((a[i] + a[i+1] + 1) * (a[i] - a[i+1])) / 2 * size;
            count += diff * size;
        } else {
            let left = k - count;
            sum += (((2 * a[i]) - (left/size) + 1) * (left/size) / 2) * size;
            sum += (a[i] - (left/size)) * (left - (left/size)*size);
            break;
        }
    }

    println!("{}", sum);
}

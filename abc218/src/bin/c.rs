#![allow(unused_imports)]
use proconio::{input, fastout};
use proconio::marker::Chars;

fn crop(s: &Vec<Vec<char>>) -> (usize, usize, usize, usize) {
  let mut t = 0;
  for y in 0..(s.len()) {
    if let Some(_) = s[y].iter().find(|&&e| e == '#') {
      t = y;
      break;
    }
  }

  let mut b = 0;
  for y in (0..s.len()).rev() {
    if let Some(_) = s[y].iter().find(|&&e| e == '#') {
      b = y;
      break;
    }
  }

  let mut l = 0;
  for x in 0..s.len() {
    if let Some(_) = (0..s.len()).find(|&y| s[y][x] == '#') {
      l = x;
      break;
    }
  }

  let mut r = 0;
  for x in (0..s.len()).rev() {
    if let Some(_) = (0..s.len()).find(|&y| s[y][x] == '#') {
      r = x;
      break;
    }
  }

  (t, b, l, r)
}

fn check_fit(s: &Vec<Vec<char>>, t: &Vec<Vec<char>>, sw: usize, sh: usize, st: usize, sl: usize, tt: usize, tl: usize) -> bool {
  for y in 0..sh {
    for x in 0..sw {
      if s[y+st][x+sl] != t[y+tt][x+tl] {
        return false;
      }
    }
  }

  return true;
}

fn check_updown(s: &Vec<Vec<char>>, t: &Vec<Vec<char>>, sw: usize, sh: usize, st: usize, sl: usize, tt: usize, tl: usize) -> bool {
  for y in 0..sh {
    for x in 0..sw {
      if s[y+st][x+sl] != t[sh-y-1+tt][sw-x-1+tl] {
        return false;
      }
    }
  }

  return true;
}

fn check_rightup(s: &Vec<Vec<char>>, t: &Vec<Vec<char>>, sw: usize, sh: usize, st: usize, sl: usize, tt: usize, tl: usize) -> bool {
  for y in 0..sh {
    for x in 0..sw {
      if s[y+st][x+sl] != t[sw-x-1+tt][y+tl] {
        return false;
      }
    }
  }

  return true;
}

fn check_leftup(s: &Vec<Vec<char>>, t: &Vec<Vec<char>>, sw: usize, sh: usize, st: usize, sl: usize, tt: usize, tl: usize) -> bool {
  for y in 0..sh {
    for x in 0..sw {
      if s[y+st][x+sl] != t[x+tt][sh-y-1+tl] {
        return false;
      }
    }
  }

  return true;
}

#[fastout]
fn main() {
  input! {
    n: usize,
    s: [Chars; n],
    t: [Chars; n],
  }

  let (st, sb, sl, sr) = crop(&s);
  let (tt, tb, tl, tr) = crop(&t);

  let sw = sr - sl + 1;
  let sh = sb - st + 1;
  let tw = tr - tl + 1;
  let th = tb - tt + 1;

  if sw == tw && sh == th {
    if check_fit(&s, &t, sw, sh, st, sl, tt, tl) {
      println!("Yes");
      return;
    }
    if check_updown(&s, &t, sw, sh, st, sl, tt, tl) {
      println!("Yes");
      return;
    }
  }
  if sw == th && sh == tw {
    if check_leftup(&s, &t, sw, sh, st, sl, tt, tl) {
      println!("Yes");
      return;
    }
    if check_rightup(&s, &t, sw, sh, st, sl, tt, tl) {
      println!("Yes");
      return;
    }
  }
  println!("No");
}

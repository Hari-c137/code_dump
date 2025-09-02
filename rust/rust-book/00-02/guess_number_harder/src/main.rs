use rand::Rng;
use std::cmp::Ordering;
use std::io;

fn main() {
    let randno = rand::rng().random_range(1..=100);
    println!("melcow to the number_guesser");
    loop {
        let mut guess = String::new();
        println!("enter your guess");
        io::stdin().read_line(&mut guess).expect("cant read_line");
        println!("your guess is {guess}");
        let guess: u32 = match guess.trim().parse() {
            Ok(num) => num,
            Err(_) => continue,
        };
        match guess.cmp(&randno) {
            Ordering::Less => println!("too small"),
            Ordering::Greater => println!("too large"),
            Ordering::Equal => {
                println!("u win!!");
                break;
            }
        }
    }
}

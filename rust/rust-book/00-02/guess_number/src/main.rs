use rand::Rng;
use std::cmp::Ordering;
use std::io;

fn main() {
    println!("Melcow to the number-guessing game");

    let rand_number = rand::thread_rng().gen_range(1..=100);

    loop {
        println!("Enter your guess");

        // guess is of type 'String' [growable, utf-8 encoded]
        let mut guess = String::new(); // new is associated function
        io::stdin()
            .read_line(&mut guess) // will return 'Result' enum
            .expect("failed to read");
        let guess: u32 = match guess.trim().parse() {
            Ok(num) => num,
            Err(_) => continue,
        };

        println!("your guessed: {}", guess);

        // 1. guess is mut because method read_line changes guess content
        // user input will always change?

        match guess.cmp(&rand_number) {
            Ordering::Less => println!("too small"),
            Ordering::Greater => println!("too big"),
            Ordering::Equal => {
                println!("u win");
                break;
            }
        }
    }
}

use std::io;

fn main() {
    let mut n1 = String::new();
    let mut n2 = String::new();

    enum Op {
        Add,
        Dif,
        Mul,
        Div,
    }

    io::stdin().read_line(&mut n1).expect("error");
    io::stdin().read_line(&mut n2).expect("error");

    let n1: u32 = match n1.trim().parse() {
        Ok(num) => num,
        Err(_) => return,
    };
    let n2: u32 = match n2.trim().parse() {
        Ok(num) => num,
        Err(_) => return,
    };

    fn cal(n1: u32, n2: u32, op: Op) {
        match op {
            Op::Add => println!("sum is {:?}", n1 + n2),
            Op::Dif => println!("dif is {:?}", n1 - n2),
            Op::Mul => println!("mul is {:?}", n1 * n2),
            Op::Div => println!("div is {:?}", n1 / n2),
        }
    }

    cal(n1, n2, Op::Add);
    cal(n1, n2, Op::Dif);
    cal(n1, n2, Op::Mul);
    cal(n1, n2, Op::Div);
}

const END: i32 = 1000000;
const F: i32 = 1000;

fn test_while() {
    let mut t = true;
    let mut i = 0;
    while t {
        i += 1;
        if i >= END {
            t = false;
        }
    }
}

fn test_break() {
    let mut i = 0;
    while true {
        i += 1;
        if i >= END {
            break;
        }
    }
}

fn main() {
    let break_start = std::time::Instant::now();
    for _ in 0..F {
        test_break();
    }
    let break_duration = break_start.elapsed();
    println!("break: {:?}", break_duration);

    let while_start = std::time::Instant::now();
    for _ in 0..F {
        test_while();
    }
    let while_duration = while_start.elapsed();
    println!("while: {:?}", while_duration);
}

use std::io;

fn maximum_odd_binary_number(s: &str) -> Option<String>{
    if s.chars().count() < 1 || s.chars().count() > 100 {return None;}

    let mut oneNum: u8 = 0;
    let mut zeroNum: u8 = 0;
    let mut oneZero: bool = false;

    for character in s.chars(){
        if character == '0'{zeroNum += 1; println!("[DEBUG] Zero encounter")}
        else if character == '1'{oneNum += 1; println!("[DEBUG] One encounter")}
    }

    println!("One = {} Zero = {}",oneNum,zeroNum);

    if oneNum == 0 {println!("No ones");return None;}
    if oneNum == 1 {oneZero = true;}

    let mut result = String::new();

    for characterAgain in 0..s.chars().count(){
        if characterAgain == s.chars().count()-1 { result.insert(s.chars().count()-1,'1');oneNum -= 1;continue;}

        if oneNum > 1{result.insert(characterAgain, '1');oneNum -= 1;continue;}
        else if zeroNum > 0 {result.insert(characterAgain, '0');zeroNum -= 1;continue;}
    }

    return Some(result); //TODO
}

fn main(){
    loop{
        println!("Please input your guess.");

        let mut mystring = String::new();

        io::stdin()
            .read_line(&mut mystring)
            .expect("Failed to read line");

        let trimmed_input = mystring.trim();

        if let Some(result) = maximum_odd_binary_number(trimmed_input) {
            println!("Result: {}", result);
        } else {
            println!("Invalid input");
        }
    }
}

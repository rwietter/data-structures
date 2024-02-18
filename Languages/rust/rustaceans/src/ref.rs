/**
 * ref keyword is used to borrow a value by reference.
 * This is useful when you want to refer to a value but not take ownership of it.
 * The use is only valid within a pattern.
 */

fn unwrap_ref() {
    let maybe_name = Some(String::from("Alice"));

    match maybe_name {
        Some(ref name) => println!("Hello, {name}"),
        _ => println!("Hello, world"),
    }

    println!("Hello again, {}", maybe_name.unwrap_or("world".into()));
}

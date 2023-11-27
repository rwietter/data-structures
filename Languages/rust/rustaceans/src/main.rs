#![allow(dead_code)]
#![allow(unused_variables)]
mod chapter_10;
mod contracts;
mod data_structures;
mod error_handling;
mod exercices;
mod hashmap;
mod move_owner;
mod slices;
mod strings;

// use slices::slices;
use exercices::median_mode;

fn main() {
    // let mut s = String::from("Hello");
    // change(&mut s);
    // os::system()
    data_structures::vector::vectors();
    slices::string_slice();
    strings::forloop();
    hashmap::hashmap();
    error_handling::error_handling();
    median_mode::median_mode();
    contracts::gessing_game();
    move_owner::move_owner();
    chapter_10::generics::pointers();
    chapter_10::traits::summarize();
}

fn change(str: &mut String) {
    (*str).push_str(", World");
}

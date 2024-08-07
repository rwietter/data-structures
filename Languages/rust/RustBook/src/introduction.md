# Introduction

Rust is a systems programming language that runs blazingly fast, prevents segfaults, and guarantees thread safety.

## Install Rust into Arch Linux

```bash
sudo pacman -S rust

# check version
rustc --version
```

## How to use Rust

### Create a new project

```bash
cargo new hello-rust
cd hello-rust
```

## Cargo commands

### Build and run

```bash
cargo build
cargo run
```

### Cargo watch

```bash
cargo install cargo-watch # install cargo-watch
sudo pacman -S cargo-watch # install cargo-watch
cargo watch -x run
```

### Build for release

```bash
cargo build --release
```

### Build and run tests

```bash
cargo test
```

### Build and run benchmarks

```bash
cargo bench
```

### Build and run documentation

```bash
cargo doc --open
```

### Build and run clippy

```bash
cargo clippy
```

### Build and run rustfmt

```bash
cargo fmt
```

### Build and run rustfix

```bash
cargo fix
```

### Build and run rust-analyzer

```bash
cargo xtask install --server
```

### Build and run cargo-audit

```bash
cargo audit
```
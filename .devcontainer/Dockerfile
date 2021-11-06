FROM rust:1.56.0-slim-buster as builder
RUN apt update && \
    apt install -y pkg-config libssl-dev && \
    cargo install cargo-compete


FROM rust:1.42.0-slim-buster
RUN rustup component add rustfmt rls rust-src rust-analysis && \
    apt update && \
    apt install -y --no-install-recommends gnupg2 ssh git && \
    apt -y clean && \
    rm -rf /var/lib/apt/lists/*
COPY --from=builder /usr/local/cargo/bin/cargo-compete /usr/local/cargo/bin/cargo-compete
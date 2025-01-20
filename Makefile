all:
	cargo build --target=x86_64-unknown-linux-gnu

build_web:
	cargo build --target=wasm32-unknown-unknown

watch_web:
	cargo watch -cx "run --target wasm32-unknown-unknown"

run:
	cargo run --target x86_64-unknown-linux-gnu

run_web:
	CARGO_TARGET_WASM32_UNKNOWN_UNKNOWN_RUNNER=wasm-server-runner cargo run --target wasm32-unknown-unknown
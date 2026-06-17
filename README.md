# C++ Layer 1 Blockchain Engine

A lightweight Layer 1 blockchain architecture built entirely from scratch in C++ to demonstrate the fundamental mechanics of distributed ledgers, cryptographic hashing, and data immutability.

## 🧠 Core Concepts Demonstrated
This engine strips away network consensus and focuses strictly on the underlying data structures of a blockchain:
- **The Genesis Block:** Automated minting of block `0` to anchor the chain.
- **Cryptographic Hashing:** Binding block index, timestamp, data, and previous hash into a single unalterable signature.
- **Immutability via Chaining:** Each new block securely stores the `Prev Hash` of the block before it. If historical data is tampered with, the cryptographic chain breaks.

## 📁 Architecture
* **`Block.h` & `Block.cpp`**: The blueprint and logic for individual blocks, including the `calculateHash()` mechanism.
* **`Blockchain.h` & `Blockchain.cpp`**: The container ledger that manages the sequential array and handles block appending.
* **`main.cpp`**: The driver file that initializes the test network, mints simulated blocks, and prints the ledger for verification.

## 🚀 How to Run Locally

**1. Compile the engine using g++:**
```bash
g++ main.cpp Block.cpp Blockchain.cpp -o blockchain_engine
```

**2. Execute the compiled program:**
* **Windows:** ```bash
.\blockchain_engine.exe
```
* **Mac/Linux:** ```bash
./blockchain_engine
```
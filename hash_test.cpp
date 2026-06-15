#include <iostream>
#include <string>
#include <functional> // This brings in std::hash

int main() {
    // We instantiate the built-in hash function
    std::hash<std::string> hashFunction;

    // 1. The Baseline Data
    std::string data1 = "Block 1: Send 10 coins to Alice";
    size_t hash1 = hashFunction(data1);

    // 2. Proving Determinism (Exact same data)
    std::string data2 = "Block 1: Send 10 coins to Alice";
    size_t hash2 = hashFunction(data2);

    // 3. Proving The Avalanche Effect (One character changed: 10 -> 90)
    std::string data3 = "Block 1: Send 90 coins to Alice";
    size_t hash3 = hashFunction(data3);

    // --- Outputting the Results ---
    std::cout << "--- Cryptographic Hashing Rules in Action ---\n\n";
    
    std::cout << "Input 1:  " << data1 << "\n";
    std::cout << "Output 1: " << hash1 << "\n\n";

    std::cout << "Input 2:  " << data2 << "\n";
    std::cout << "Output 2: " << hash2 << " (Determinism: Matches Output 1)\n\n";

    std::cout << "Input 3:  " << data3 << "\n";
    std::cout << "Output 3: " << hash3 << " (Avalanche: Completely different!)\n";

    return 0;
}
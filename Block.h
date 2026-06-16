#ifndef BLOCK_H
#define BLOCK_H

#include <string>
#include <ctime>

class Block {
public:
    int index;              // The block's position in the chain (0, 1, 2...)
    time_t timestamp;       // The exact time the block was created
    std::string data;       // The ledger payload (e.g., "Alice sent Bob 5 coins")
    std::string prevHash;   // The cryptographic signature of the previous block
    std::string hash;       // The cryptographic signature of this current block

    // Constructor to initialize a new block when it's minted
    Block(int idx, const std::string& blockData, const std::string& previousHash);

    // Method to calculate the block's hash based on its combined attributes
    std::string calculateHash() const;
};

#endif // BLOCK_H
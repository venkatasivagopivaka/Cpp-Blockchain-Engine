#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include <vector>
#include "Block.h"

class Blockchain {
private:
    // The actual linear ledger holding all your blocks sequentially
    std::vector<Block> chain; 

    // Internal helper function to mint the historic first block ("Genesis Block")
    Block createGenesisBlock();

public:
    // Constructor: Automatically boots up the network and mints the Genesis block
    Blockchain();

    // Appends a new block containing fresh data/transactions to the chain
    void addBlock(const std::string& data);

    // Read-only getter to view the entire blockchain history
    std::vector<Block> getChain() const;

    // Helper function to fetch the most recently added block
    Block getLatestBlock() const;
};

#endif // BLOCKCHAIN_H
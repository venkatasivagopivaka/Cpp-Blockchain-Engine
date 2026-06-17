#include "Blockchain.h"

// Constructor: Executes when the blockchain is initialized
Blockchain::Blockchain() {
    // Automatically mints and pushes the Genesis block as the very first element (index 0)
    chain.push_back(createGenesisBlock());
}

// Internal Helper: Generates the foundational block #0
Block Blockchain::createGenesisBlock() {
    // Index: 0, Data: "Genesis Block", PrevHash: "0"
    return Block(0, "Genesis Block", "0");
}

// Returns the absolute latest block currently sitting at the end of the chain
Block Blockchain::getLatestBlock() const {
    return chain.back();
}

// Appends a new block to the chain and handles the cryptographic link
void Blockchain::addBlock(const std::string& data) {
    // 1. Determine the new block's index position
    int newIndex = chain.size();
    
    // 2. Fetch the cryptographic hash of the current last block to act as the link
    std::string previousHash = getLatestBlock().hash;
    
    // 3. Instantiate the new block (this automatically triggers its internal calculateHash())
    Block newBlock(newIndex, data, previousHash);
    
    // 4. Securely push the newly minted block onto the immutable ledger array
    chain.push_back(newBlock);
}

// Read-only getter to securely view the entire ledger history
std::vector<Block> Blockchain::getChain() const {
    return chain;
}
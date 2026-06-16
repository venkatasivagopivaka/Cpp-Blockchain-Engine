#include "Block.h"
#include <sstream>
#include <functional>

// Constructor: Initializes the block fields and generates its unique hash
Block::Block(int idx, const std::string& blockData, const std::string& previousHash) {
    index = idx;
    data = blockData;
    prevHash = previousHash;
    timestamp = std::time(nullptr); // Grabs the current real-world timestamp
    hash = calculateHash();         // Automatically mints the hash upon creation
}

// Generates a cryptographic fingerprint by binding all block data together
std::string Block::calculateHash() const {
    std::stringstream ss;
    
    // Bind all attributes into a single continuous stream of data
    ss << index << timestamp << data << prevHash;
    
    // Use the C++ Standard Library hashing algorithm to turn the stream into a unique number
    std::hash<std::string> nativeHasher;
    size_t numericHash = nativeHasher(ss.str());
    
    // Return the final hash as a clean string representation
    return std::to_string(numericHash);
}
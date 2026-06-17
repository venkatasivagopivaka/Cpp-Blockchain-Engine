#include <iostream>
#include <iomanip>
#include "Blockchain.h"

// Helper function to print a clean visual divider in the terminal
void printLine() {
    std::cout << std::string(60, '-') << "\n";
}

int main() {
    std::cout << "Initializing Standard Test Network...\n";
    Blockchain testLedger;
    printLine();

    // Minting new blocks with generic, simple learning data
    std::cout << "Minting Block 1...\n";
    testLedger.addBlock("Transaction: Alice sent Bob 50 coins");

    std::cout << "Minting Block 2...\n";
    testLedger.addBlock("Transaction: Bob sent Charlie 20 coins");

    std::cout << "Minting Block 3...\n";
    testLedger.addBlock("Transaction: Charlie sent Dave 5 coins");
    printLine();

    std::cout << "VERIFYING LEDGER INTEGRITY & DATA CHAINING:\n";
    printLine();

    // Loop through the blockchain and print out every block's cryptographic details
    std::vector<Block> completeChain = testLedger.getChain();
    
    for (const Block& block : completeChain) {
        std::cout << "Block #" << block.index << "\n";
        std::cout << "Timestamp: " << block.timestamp << "\n";
        std::cout << "Data:      " << block.data << "\n";
        std::cout << "Prev Hash: " << block.prevHash << "\n";
        std::cout << "Curr Hash: " << block.hash << "\n";
        printLine();
    }

    return 0;
}
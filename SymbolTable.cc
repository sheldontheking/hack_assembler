//
//  SymbolTable.cpp
//  assembler
//
//  Created by Zengyu Wei on 11/1/18.
//  Copyright © 2018 Zengyu Wei. All rights reserved.
//

#include "SymbolTable.hpp"
#include <map>
#include <iostream>

using namespace std;

SymbolTable::SymbolTable() {
    symbolMap.insert(pair <string, int> ("SP", 0));
    symbolMap.insert(pair <string, int> ("LCL", 1));
    symbolMap.insert(pair <string, int> ("ARG", 2));
    symbolMap.insert(pair <string, int> ("THIS", 3));
    symbolMap.insert(pair <string, int> ("THAT", 4));
    symbolMap.insert(pair <string, int> ("SCREEN", 16384));
    symbolMap.insert(pair <string, int> ("KBD", 24576));
    
    symbolMap.insert(pair <string, int> ("R0", 0));
    symbolMap.insert(pair <string, int> ("R1", 1));
    symbolMap.insert(pair <string, int> ("R2", 2));
    symbolMap.insert(pair <string, int> ("R3", 3));
    symbolMap.insert(pair <string, int> ("R4", 4));
    symbolMap.insert(pair <string, int> ("R5", 5));
    symbolMap.insert(pair <string, int> ("R6", 6));
    symbolMap.insert(pair <string, int> ("R7", 7));
    symbolMap.insert(pair <string, int> ("R8", 8));
    symbolMap.insert(pair <string, int> ("R9", 9));
    symbolMap.insert(pair <string, int> ("R10", 10));
    symbolMap.insert(pair <string, int> ("R11", 11));
    symbolMap.insert(pair <string, int> ("R12", 12));
    symbolMap.insert(pair <string, int> ("R13", 13));
    symbolMap.insert(pair <string, int> ("R14", 14));
    symbolMap.insert(pair <string, int> ("R15", 15));
    
    //test
//    addEntry("asdf", 100);
//    cout << contains("asdf") << endl;
//    cout << getAddress("asdf") << endl;
}

void SymbolTable::addEntry(string symbol, int address) {
    if(symbolMap.find(symbol) == symbolMap.end()) {
        symbolMap.insert(pair <string, int> (symbol, address));
        cout << "added symbol:" << symbol << " address: " << address << endl;
    }
}

bool SymbolTable::contains(string symbol) {
    if(symbolMap.find(symbol) != symbolMap.end()) {
        return true;
    }
    return false;
}

int SymbolTable::getAddress(string symbol) {
    if(symbolMap.find(symbol) != symbolMap.end()) {
        return symbolMap[symbol];
    } else {
        cout << "error: can not find symbol" << endl;
    }
    return 0;
}

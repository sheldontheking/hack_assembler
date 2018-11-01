//
//  SymbolTable.hpp
//  assembler
//
//  Created by Zengyu Wei on 11/1/18.
//  Copyright © 2018 Zengyu Wei. All rights reserved.
//

#ifndef SymbolTable_hpp
#define SymbolTable_hpp

#include <stdio.h>
#include <string>
using namespace std;

class SymbolTable {
public:
    SymbolTable();
    void addEntry(string symbol, int address);
    bool contains(string symbol);
    int getAddress(string symbol);
    
};
#endif /* SymbolTable_hpp */

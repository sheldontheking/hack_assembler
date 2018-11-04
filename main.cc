//
//  main.cpp
//  assembler
//
//  Created by Zengyu Wei on 10/25/18.
//  Copyright © 2018 Zengyu Wei. All rights reserved.
//
#include <fstream>
#include <iostream>
#include <bitset>
#include "Parser.hpp"
#include "SymbolTable.hpp"
#include "CodeToB.hpp"
using namespace std;

int main(int argc, const char * argv[]) {
    
    //block of code for opening file
    string asmName, assemName;
    ofstream assemFile;
    if (argc < 1) {
        cout << "please enter file name" << endl;
        return 0;
    } else {
        asmName = argv[1];
        assemName = argv[2];
    }
    
    
    Parser firstP(asmName);
    SymbolTable symbolTable;
    
    int lineNumberMain = 0;
    
    //first pass
    while(firstP.hasMoreCommands()) {
        firstP.advance();
        
        if(firstP.commandType() == '!' || firstP.commandType() == 'L') {
            symbolTable.addEntry(firstP.symbol(), lineNumberMain);
        }
        
        if(firstP.commandType() == 'A' || firstP.commandType() == 'C') {
            lineNumberMain++;
        }
    }
    
    //second pass
    
    CodeToB translate;
    Parser secondP(asmName);
    assemFile.open(assemName);
    
    if(assemFile.is_open()) {
        cout << "output file opened" << endl;
    }
    
    while(secondP.hasMoreCommands()) {
        secondP.advance();
        
        if(secondP.commandType() == 'A') {
            assemFile << "0";
            string temp = secondP.symbol();
            cout << "entered here" << endl;
            if(find_if(temp.begin(), temp.end(), ::isalpha) == temp.end()) {
                
                bitset<15> binary_A (stoi(temp));
                assemFile << binary_A << endl;
            }
        } else if(secondP.commandType() == 'C') {
            
        }
    }
    
    assemFile.close();
    return 0;
}

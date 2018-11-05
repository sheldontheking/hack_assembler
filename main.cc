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
        
        if(firstP.commandType() == 'L') {
            symbolTable.addEntry(firstP.symbol(), lineNumberMain);
            //cout << "symbol is:" << firstP.symbol() << " line number is: " << lineNumberMain<<endl;
        } else if(firstP.commandType() == 'A' || firstP.commandType() == 'C') {
            lineNumberMain++;
        }
    }
    
    //second pass
    
    CodeToB translate;
    Parser secondP(asmName);
    assemFile.open(assemName);
    int newPos = 16;
    
    if(assemFile.is_open()) {
        cout << "output file opened" << endl;
    }
    
    while(secondP.hasMoreCommands()) {
        secondP.advance();
        
        if(secondP.commandType() == 'A') {
            assemFile << "0";
            string temp = secondP.symbol();
            //cout << "current working on symbol:" << temp << endl;
            cout << "added symbol:" << temp << "\t"  << (symbolTable.contains(temp)) << endl;
            
            if(find_if(temp.begin(), temp.end(), ::isalpha) == temp.end()) {
                bitset<15> binary_A (stoi(temp));
                assemFile << binary_A << endl;
            } else if(!symbolTable.contains(temp)) {
                symbolTable.addEntry(temp, newPos++);
            }
            
            if(symbolTable.contains(temp)) {
                bitset<15> binary_B (symbolTable.getAddress(temp));
                assemFile << binary_B << endl;
            }
        } else if(secondP.commandType() == 'C') {
            assemFile << "111";
            assemFile << translate.comp(secondP.comp());
            assemFile << translate.dest(secondP.dest());
            assemFile << translate.jump(secondP.jump()) << endl;
        }
    }
    
    assemFile.close();
    return 0;
}

//
//  Parser.cpp
//  assembler
//
//  Created by Zengyu Wei on 10/31/18.
//  Copyright © 2018 Zengyu Wei. All rights reserved.
//
#include <map>
#include "Parser.hpp"

Parser::Parser() {
    //open file stream, print message if open successfully
    asmFile.open(asmName, ios::in);
    if(asmFile.is_open()) {
        cout << "file found and opened" << endl;
    }
    
    //initialize the map for A/C instruction recognition
    commandTable.inert(pair <char, char> ('@', 'A'));
    commandTable.inert(pair <char, char> ('=', 'C'));
    commandTable.inert(pair <char, char> (';', 'C'));
    commandTable.inert(pair <char, char> ('A', 'C'));
    commandTable.inert(pair <char, char> ('M', 'C'));
    commandTable.inert(pair <char, char> ('D', 'C'));
    commandTable.inert(pair <char, char> ('-', 'C'));
    commandTable.inert(pair <char, char> ('!', 'C'));
    commandTable.inert(pair <char, char> ('+', 'C'));
    commandTable.inert(pair <char, char> ('&', 'C'));
    commandTable.inert(pair <char, char> ('|', 'C'));
    commandTable.inert(pair <char, char> ('(', 'C'));
}

bool Parser::hasMoreCommands() {
    return !asmFile.eof();
}

string Parser::advance() {
    bool commandFound = false;
    int lineNum = 0;
    
}
          
string Parser::removeComment() {
    size_t commentPos = 
    currentCommand =
}

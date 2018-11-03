//
//  Parser.cpp
//  assembler
//
//  Created by Zengyu Wei on 10/31/18.
//  Copyright © 2018 Zengyu Wei. All rights reserved.
//
#include <map>
#include <iostream>
#include "Parser.hpp"

Parser::Parser(string asmName) {
    //open file stream, print message if open successfully
    asmFile.open(asmName, ios::in);
    if(asmFile.is_open()) {
        cout << "file found and opened" << endl;
    }
    
    //initialize the map for A/C instruction recognition
    commandTable.insert(pair <char, char> ('@', 'A'));
    commandTable.insert(pair <char, char> ('=', 'C'));
    commandTable.insert(pair <char, char> (';', 'C'));
    commandTable.insert(pair <char, char> ('A', 'C'));
    commandTable.insert(pair <char, char> ('M', 'C'));
    commandTable.insert(pair <char, char> ('D', 'C'));
    commandTable.insert(pair <char, char> ('-', 'C'));
    commandTable.insert(pair <char, char> ('!', 'C'));
    commandTable.insert(pair <char, char> ('+', 'C'));
    commandTable.insert(pair <char, char> ('&', 'C'));
    commandTable.insert(pair <char, char> ('|', 'C'));
    commandTable.insert(pair <char, char> ('(', 'C'));
}

bool Parser::hasMoreCommands() {
    return !asmFile.eof();
}

void Parser::advance() {
    bool commandFound = false;
    int lineNum = 0;
    
    while(!commandFound && getline(asmFile, currentCommand)) {
        
    }
}
          
string Parser::removeComment() {
    size_t commentPos = currentCommand.find("//");
    if(commentPos != string::npos) {
        currentCommand = currentCommand.erase(commentPos, currentCommand.length());
    }
    return currentCommand;
}

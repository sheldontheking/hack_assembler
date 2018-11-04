//
//  Parser.cpp
//  assembler
//
//  Created by Zengyu Wei on 10/31/18.
//  Copyright © 2018 Zengyu Wei. All rights reserved.
//
#include <map>
#include <iostream>
#include <algorithm>
#include <string>
#include "Parser.hpp"

Parser::Parser(string asmName) {
    //open file stream, print message if open successfully
    asmFile.open(asmName, ios::in);
    if(asmFile.is_open()) {
        cout << "file found and opened" << endl;
    }
    
    //initialize the map for A/C instruction recognition
    commandMap.insert(pair <char, char> ('@', 'A'));
    commandMap.insert(pair <char, char> ('A', 'C'));
    commandMap.insert(pair <char, char> ('M', 'C'));
    commandMap.insert(pair <char, char> ('D', 'C'));
    commandMap.insert(pair <char, char> ('-', 'C'));
    commandMap.insert(pair <char, char> ('!', 'C'));
    commandMap.insert(pair <char, char> ('(', 'L'));
    
    //line number start at 0
    lineNum = 0;
    //testing
    cout << symbol("D=M") << endl;;
}

bool Parser::hasMoreCommands() {
    return !asmFile.eof();
}

void Parser::advance() {
    bool commandFound = false;
    string curr;
    
    while(!commandFound && getline(asmFile, curr)) {
        curr = removeComment(curr);
        if(!curr.empty()) {
            commandFound = true;
            lineNum++;
        }
    }
    
    currentCommand = curr;
}

char Parser::commandType(string cleanCommand) {
    if(commandMap.find(cleanCommand[0]) != commandMap.end()) {
        return commandMap[cleanCommand[0]];
    }
    return '!';
}

string Parser::symbol(string temp) {
    currentCommand.erase(remove_if(currentCommand.begin(), currentCommand.end(), ::isalnum), currentCommand.end());
    return currentCommand;
}

string Parser::dest() {
    
}

string Parser::removeComment(string curr) {
    //remove space and parts of the string after "//"
    curr.erase(remove_if(curr.begin(), curr.end(), ::isspace), curr.end());
    size_t commentPos = curr.find("//");
    if(commentPos != string::npos) {
        curr = curr.erase(commentPos, curr.length());
    }
    return curr;
}

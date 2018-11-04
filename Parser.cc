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
    currentCommand = "ADM;JMP";
    cout << jump() << endl;
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

char Parser::commandType() {
    if(commandMap.find(currentCommand[0]) != commandMap.end()) {
        return commandMap[currentCommand[0]];
    }
    return '!';
}

string Parser::symbol() {
    currentCommand.erase(remove_if(currentCommand.begin(), currentCommand.end(), ::ispunct), currentCommand.end());
    cout << currentCommand << endl;
    return currentCommand;
}

string Parser::dest() {
    size_t equalPos = currentCommand.find("=");
    if(equalPos != string::npos) {
        return currentCommand.substr(0,equalPos);
    } else {
        return "error: can not find equal sign, when trying to find dest";
    }
    
    return "error: command is unexpected";
}

string Parser::comp() {
    size_t equalPos = currentCommand.find("=");
    size_t semiPos = currentCommand.find(";");
    
    if(equalPos != string::npos) {
        if(semiPos != string::npos) {
            //dest = comp ; jump
            return currentCommand.substr(equalPos + 1, semiPos - equalPos - 1);
        }
        //dest = comp
        return currentCommand.substr(equalPos + 1, currentCommand.length() - equalPos - 1);
    } else {
        //comp ; jump
        return currentCommand.substr(0, semiPos);
    }
    
    return "error: command is unexpected";
}

string Parser::jump() {
    size_t semiPos = currentCommand.find(";");
    
    if(semiPos != string::npos) {
        return currentCommand.substr(semiPos+1, currentCommand.length());
    }
    
    return "error: command is unexpected";
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

int Parser::getLineNum() {
    return lineNum;
}

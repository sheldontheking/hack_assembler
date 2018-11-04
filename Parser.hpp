//
//  Parser.hpp
//  assembler
//
//  Created by Zengyu Wei on 10/31/18.
//  Copyright © 2018 Zengyu Wei. All rights reserved.
//

#ifndef Parser_hpp
#define Parser_hpp

#include <map>
#include <algorithm>
#include <fstream>
#include <stdio.h>
#include <string>
using namespace std;

class Parser
{
public:
    Parser(string asmName);
    bool hasMoreCommands();
    void advance();
    char commandType(string cleanCommand);
    string symbol(string temp);
    string dest();
    string comp();
    string jump();
private:
    int lineNum;
    ifstream asmFile;
    string currentCommand;
    map<char,char> commandMap;
    string removeComment(string curr);
};
#endif /* Parser_hpp */

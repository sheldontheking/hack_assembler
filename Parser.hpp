//
//  Parser.hpp
//  assembler
//
//  Created by Zengyu Wei on 10/31/18.
//  Copyright © 2018 Zengyu Wei. All rights reserved.
//

#ifndef Parser_hpp
#define Parser_hpp

#include <stdio.h>
#include <string>
using namespace std;

class Parser
{
public:
    Parser(string fileName){};
    bool hasMoreCommands();
    void advance();
    char commandType(string cleanCommand);
    string symbol();
    string dest();
    string comp();
    string jump();
private:
    ifstream asmFile;
    string currentCommand;
    map<char,char> commandTable;
    string removeComment();
};
#endif /* Parser_hpp */

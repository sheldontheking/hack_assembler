//
//  main.cpp
//  assembler
//
//  Created by Zengyu Wei on 10/25/18.
//  Copyright © 2018 Zengyu Wei. All rights reserved.
//
#include <fstream>
#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    
    //block of code for opening file
    string asmName;
    
    if (argc < 1) {
        cout << "please enter file name" << endl;
        return 0;
    } else {
        asmName = argv[1];
    }
    
    ifstream asmFile;
    asmFile.open(asmName, ios::in);
    if(asmFile.is_open()) {
        cout << "file found and opened" << endl;
    }
    
    string currentLine;
    size_t comment_pos = -1, a_pos = -1, c_pos = -1;
    
    while(getline(asmFile,currentLine)) {
        
        comment_pos = currentLine.find("//");
        a_pos = currentLine.find("@");
        
        //current line is comment
        if(comment_pos >= 0 && comment_pos <= currentLine.size()) {
            continue;
        }
        
        //corrent line is a instruciton
        if(a_pos >= 0 && a_pos <= currentLine.size()) {
            //TODO, add a instruction translation
        }
        
        //current line is c instruction
        if(c_pos >= 0 && c_pos <= currentLine.size()) {
            //TODO, add a instruction translation
        }
        cout << currentLine << endl;
        
        
        comment_pos = -1;
        
    }
    
    return 0;
}

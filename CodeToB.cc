//
//  CodeToB.cpp
//  assembler
//
//  Created by Zengyu Wei on 11/1/18.
//  Copyright © 2018 Zengyu Wei. All rights reserved.
//

#include "CodeToB.hpp"

CodeToB::CodeToB() {
    destToB.insert(pair <string, string> ("", "000"));
    destToB.insert(pair <string, string> ("M", "001"));
    destToB.insert(pair <string, string> ("D", "010"));
    destToB.insert(pair <string, string> ("MD", "011"));
    destToB.insert(pair <string, string> ("A", "100"));
    destToB.insert(pair <string, string> ("AM", "101"));
    destToB.insert(pair <string, string> ("AD", "110"));
    destToB.insert(pair <string, string> ("AMD", "111"));
    
    compToB.insert(pair <string, string> ("0", "0101010"));
    compToB.insert(pair <string, string> ("1", "0111111"));
    compToB.insert(pair <string, string> ("-1", "0111010"));
    compToB.insert(pair <string, string> ("D", "0001100"));
    compToB.insert(pair <string, string> ("A", "0110000"));
    compToB.insert(pair <string, string> ("!D", "0001101"));
    compToB.insert(pair <string, string> ("!A", "0110001"));
    compToB.insert(pair <string, string> ("-D", "0001111"));
    compToB.insert(pair <string, string> ("-A", "0110011"));
    compToB.insert(pair <string, string> ("D+1", "0011111"));
    compToB.insert(pair <string, string> ("A+1", "0110111"));
    compToB.insert(pair <string, string> ("D-1", "0001110"));
    compToB.insert(pair <string, string> ("A-1", "0110010"));
    compToB.insert(pair <string, string> ("D+A", "0000010"));
    compToB.insert(pair <string, string> ("D-A", "0010011"));
    compToB.insert(pair <string, string> ("A-D", "0000111"));
    compToB.insert(pair <string, string> ("D&A", "0000000"));
    compToB.insert(pair <string, string> ("D|A", "0010101"));
    compToB.insert(pair <string, string> ("M", "1110000"));
    compToB.insert(pair <string, string> ("!M", "1110001"));
    compToB.insert(pair <string, string> ("-M", "1110011"));
    compToB.insert(pair <string, string> ("M+1", "1110111"));
    compToB.insert(pair <string, string> ("M-1", "1110010"));
    compToB.insert(pair <string, string> ("D+M", "1000010"));
    compToB.insert(pair <string, string> ("D-M", "1010011"));
    compToB.insert(pair <string, string> ("M-D", "1000111"));
    compToB.insert(pair <string, string> ("D&M", "1000000"));
    compToB.insert(pair <string, string> ("D|M", "1010101"));
    
    jumpToB.insert(pair <string, string> ("", "000"));
    jumpToB.insert(pair <string, string> ("JGT", "001"));
    jumpToB.insert(pair <string, string> ("JEQ", "010"));
    jumpToB.insert(pair <string, string> ("JGE", "011"));
    jumpToB.insert(pair <string, string> ("JLT", "100"));
    jumpToB.insert(pair <string, string> ("JNE", "101"));
    jumpToB.insert(pair <string, string> ("JLE", "110"));
    jumpToB.insert(pair <string, string> ("JMP", "111"));
}

string CodeToB::dest(string mnemonic) {
    if(destToB.find(mnemonic) != destToB.end()) {
        return destToB[mnemonic];
    }
    return "error: can not find dest command";
}

string CodeToB::comp(string mnemonic) {
    if(compToB.find(mnemonic) != compToB.end()) {
        return compToB[mnemonic];
    }
    return "error: can not find comp command";
}

string CodeToB::jump(string mnemonic) {
    if(jumpToB.find(mnemonic) != jumpToB.end()) {
        return jumpToB[mnemonic];
    }
    return "error: can not find jump command";
}

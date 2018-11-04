//
//  main.cpp
//  assembler
//
//  Created by Zengyu Wei on 10/25/18.
//  Copyright © 2018 Zengyu Wei. All rights reserved.
//
#include <fstream>
#include <iostream>
#include "Parser.hpp"
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
    
    Parser p(asmName);
    
    return 0;
}

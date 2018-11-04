//
//  CodeToB.hpp
//  assembler
//
//  Created by Zengyu Wei on 11/1/18.
//  Copyright © 2018 Zengyu Wei. All rights reserved.
//

#ifndef CodeToB_hpp
#define CodeToB_hpp

#include <stdio.h>
#include <string>
#include <map>

using namespace std;

class CodeToB {
public:
    CodeToB();
    string dest(string mnemonic);
    string comp(string mnemonic);
    string jump(string mnemonic);
private:
    map<string,string> destToB;
    map<string,string> compToB;
    map<string,string> jumpToB;
};
#endif /* CodeToB_hpp */

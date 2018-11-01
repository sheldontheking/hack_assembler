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

using namespace std;

class CodeToB {
public:
    CodeToB();
    int dest(string mnemonic);
    int comp(string mnemonic);
    int jump(string mnemonic);
    
};
#endif /* CodeToB_hpp */

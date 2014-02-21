//
//  plug.h
//  Enigma
//
//  Created by Petr Mánek on 21.02.14.
//  Copyright (c) 2014 TEEN, s.r.o. All rights reserved.
//

#ifndef __Enigma__plug__
#define __Enigma__plug__

#include <iostream>
#import "util.h"

class plugboard {
public:
    plugboard();
    
    void set(char,char);
    void remove(char);
    void reset();
    
    char encode(char);
    
private:
    int m_mappings[26];
    
    int index(char);
    
};

#endif /* defined(__Enigma__plug__) */

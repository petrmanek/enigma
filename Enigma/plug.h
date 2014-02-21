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
    // Initialize new empty plugboard
    plugboard();
    
    // Connect two characters (and remove any previous connections of theirs)
    void set(char,char);
    
    // Remove any connection of a character
    void remove(char);
    
    // Remove all connections
    void reset();
    
    // Encode character using current configuration
    char encode(char);
    
private:
    int m_mappings[26];
    const int empty = -1;
    
    int index(char);
    
};

#endif /* defined(__Enigma__plug__) */

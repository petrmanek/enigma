//
//  plug.cpp
//  Enigma
//
//  Created by Petr Mánek on 21.02.14.
//  Copyright (c) 2014 TEEN, s.r.o. All rights reserved.
//

#include "plug.h"

#pragma mark - Constructor
plugboard::plugboard() {
    // start with clean slate
    this->reset();
}


#pragma mark - Utilities
void plugboard::reset() {
    // point all 26 plugs to themselves
    for (int i = 0; i < 26; i++) {
        this->m_mappings[i] = plugboard::empty;
    }
}

int plugboard::index(char c) {
    // check if character is alphabetic
    if (!isalpha(c))
        throw std::runtime_error("Lowercase or uppercase ASCII character expected.");
    
    // ensure it's uppercase
    char c_norm = toupper(c);
    
    // subtract it from A, so that we begin from zero
    return c_norm - ASCII_START;
}


#pragma mark - Accessors
void plugboard::set(char c, char d) {
    // find indexes
    int c_idx = this->index(c);
    int d_idx = this->index(d);
    
    // break all existing connections
    this->remove(c);
    this->remove(d);
    
    // set up new connections
    this->m_mappings[c_idx] = d_idx;
    this->m_mappings[d_idx] = c_idx;
}

void plugboard::remove(char c) {
    // find index
    int c_idx = this->index(c);
    
    // find connected plug
    if (this->m_mappings[c_idx] != plugboard::empty) {
        // point connected plug to itself
        this->m_mappings[this->m_mappings[c_idx]] = plugboard::empty;
        
        // set this plug to itself
        this->m_mappings[c_idx] = plugboard::empty;
    }
}


#pragma mark - Encoding
char plugboard::encode(char c) {
    // find index
    int c_idx = this->index(c);
    
    // find connected plug
    if (this->m_mappings[c_idx] == plugboard::empty) {
        // if there's none, return the original character
        return c;
    } else {
        // if there's any, return the substituted character
        return ASCII_START + this->m_mappings[c_idx];
    }
}

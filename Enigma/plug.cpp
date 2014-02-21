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
    this->reset();
}


#pragma mark - Utilities
void plugboard::reset() {
    for (int i = 0; i < 26; i++) {
        this->m_mappings[i] = -1;
    }
}

int plugboard::index(char c) {
    if (!isalpha(c))
        throw std::runtime_error("Lowercase or uppercase ASCII character expected.");
    
    char c_norm = toupper(c);
    return c_norm - ASCII_START;
}


#pragma mark - Accessors
void plugboard::set(char c, char d) {
    int c_idx = this->index(c);
    int d_idx = this->index(d);
    
    this->m_mappings[c_idx] = d_idx;
    this->m_mappings[d_idx] = c_idx;
}

void plugboard::remove(char c) {
    int c_idx = this->index(c);
    
    if (this->m_mappings[c_idx] != -1) {
        this->m_mappings[this->m_mappings[c_idx]] = -1;
        this->m_mappings[c_idx] = -1;
    }
}


#pragma mark - Encoding
char plugboard::encode(char c) {
    int c_idx = this->index(c);
    
    if (this->m_mappings[c_idx] == -1) {
        return c;
    } else {
        return ASCII_START + this->m_mappings[c_idx];
    }
}
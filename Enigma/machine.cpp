//
//  machine.cpp
//  Enigma
//
//  Created by Petr Mánek on 21.02.14.
//  Copyright (c) 2014 TEEN, s.r.o. All rights reserved.
//

#include "machine.h"

#pragma mark - Constructor
machine::machine() {
    rotors = std::vector<rotor>();
}

#pragma mark - Encoding
char machine::encode(char c) {
    // few checks
    int nrotors = (int)this->rotors.size();
    if (nrotors == 0)
        throw std::runtime_error("No rotors found. Please set up at least one rotor.");
    
    if (!this->reflector.is_reflector())
        throw std::runtime_error("The reflector must have symetric wiring. Check rotor::is_reflector().");
    
    char e = c;
    
    // enter plugboard
    e = this->plugs.encode(e);
    
    // enter rotors in forward direction
    for (int i = nrotors - 1; i >= 0; i--) {
        e = this->rotors[i].encode_forward(e);
    }

    // enter reflector
    e = this->reflector.encode_forward(e);
    
    // enter rotors in backward direction
    for (int i = 0; i < nrotors; i++) {
        e = this->rotors[i].encode_backward(e);
    }
    
    // enter plugboard
    e = this->plugs.encode(e);
    
    // step last rotor (and possibly others)
    this->rotor_turnover(nrotors - 1);
    
    return e;
}

void machine::rotor_turnover(int i) {
    if (i < 0) return;
    
    if (this->rotors[i].is_in_turnover_position()) {
        this->rotor_turnover(i - 1);
    }
    
    this->rotors[i].step();
}

std::string machine::encode_string(std::string s) {
    std::string encoded = "";
    
    for (int i = 0; i < s.length(); i++) {
        encoded += this->encode(s[i]);
    }
    
    return encoded;
}
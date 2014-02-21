//
//  machine.cpp
//  Enigma
//
//  Created by Petr Mánek on 21.02.14.
//  Copyright (c) 2014 TEEN, s.r.o. All rights reserved.
//

#include "machine.h"

#pragma mark - Constructor
machine::machine() : m_r1(w1), m_r2(w2), m_r3(w3), m_reflector(w_ra) {
    
}

#pragma mark - Encoding
char machine::encode(char c) {
    std::cout << "\n---\n(rotors before: " << this->m_r1.get_offset() << this->m_r2.get_offset() << this->m_r3.get_offset() << ") \n";
    
    // current flow: input -> plugboard(f) -> r3(f) -> r2(f) -> r1(f) -> reflector -> r1(b) -> r2(b) -> r3(b) -> plugboard(b) -> output
    char e = c;
    std::cout << e << " -> ";
    
    e = this->plugs.encode(e);
    std::cout << "(PB) -> " << e << " -> ";
    
    e = this->m_r3.encode_forward(e);
    std::cout << "(R3) -> " << e << " -> ";

    e = this->m_r2.encode_forward(e);
    std::cout << "(R2) -> " << e << " -> ";

    e = this->m_r1.encode_forward(e);
    std::cout << "(R1) -> " << e << " -> ";

    e = this->m_reflector.encode_forward(e);
    std::cout << "(RF) -> " << e << " -> ";
    
    e = this->m_r1.encode_backward(e);
    std::cout << "(R1) -> " << e << " -> ";

    e = this->m_r2.encode_backward(e);
    std::cout << "(R2) -> " << e << " -> ";

    e = this->m_r3.encode_backward(e);
    std::cout << "(R3) -> " << e << " -> ";

    
    e = this->plugs.encode(e);
    std::cout << "(PB) -> " << e << "\n";
    
    
    // todo: step recursive for any number of rotors
    if (this->m_r3.is_in_turnover_position()) {
        if (this->m_r2.is_in_turnover_position()) {
            if (this->m_r1.is_in_turnover_position()) {
                // ... and so on
            }
            
            this->m_r1.step();
        }
        
        this->m_r2.step();
    }
    this->m_r3.step();
    
    std::cout << "(rotors after: " << this->m_r1.get_offset() << this->m_r2.get_offset() << this->m_r3.get_offset() << ") \n";
    //std::cout << "Char " << c << " encoded as " << e;
    
    return e;
}

std::string machine::encode_string(std::string s) {
    std::string encoded = "";
    
    for (int i = 0; i < s.length(); i++) {
        encoded += this->encode(s[i]);
    }
    
    return encoded;
}
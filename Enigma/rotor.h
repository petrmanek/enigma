//
//  rotor.h
//  Enigma
//
//  Created by Petr Mánek on 20.02.14.
//  Copyright (c) 2014 TEEN, s.r.o. All rights reserved.
//

#ifndef __Enigma__rotor__
#define __Enigma__rotor__

#include <iostream>
#include <string>

enum RotorType {
    c1, c2, c3, // Commercial Enigma A, B - 1924
    gr1, gr2, gr3, gr_ukw, gr_etw, // German Railway (Rocket) - 1941
    k1, k2, k3, k_ukw, k_etw, // Swiss K - 1939
    w1, w2, w3, w4, w5, w6, w7, w8, // Military Rotors - 1930-1939
    w_beta, w_gamma, w_ra, w_rb, w_rc, w_rbt, w_rct, w_etw // Military Rotors - 1940-1942
};

class Rotor {
public:
    // Initialize rotor with known wiring
    Rotor(RotorType);
    
    // Initialize rotor with custom wiring
    Rotor(std::string);
    
    // Gets current offset of the rotor (as letter)
    char get_offset();
    
    // Sets current offset of the rotor (as integer modulo 26)
    void set_offset(int);
    
    // Increments current offset
    void step();
    
    // Encodes character without stepping the rotor.
    char peek(char);
    
    // Encodes character and steps the rotor.
    char encode(char);
    
private:
    int m_offset;
    std::string m_wiring;
    
    std::string known_wiring(RotorType);
};

#endif /* defined(__Enigma__rotor__) */

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
#include <vector>
#include "util.h"

enum rotor_wiring {
    straight, // Default wiring
    c1, c2, c3, // Commercial Enigma A, B - 1924
    gr1, gr2, gr3, gr_ukw, gr_etw, // German Railway (Rocket) - 1941
    k1, k2, k3, k_ukw, k_etw, // Swiss K - 1939
    w1, w2, w3, w4, w5, w6, w7, w8, // Military Rotors - 1930-1939
    w_beta, w_gamma, w_ra, w_rb, w_rc, w_rbt, w_rct, w_etw // Military Rotors - 1940-1942
};

class rotor {
public:
    // Initialize rotor with default wiring
    rotor();
    
    // Initialize rotor with known wiring
    rotor(rotor_wiring);
    
    // Initialize rotor with custom wiring and turnover positions
    rotor(std::string, std::vector<int>);
    
    // Gets current offset of the rotor (as letter)
    char get_offset();
    
    // Sets current offset of the rotor (as integer modulo 26)
    void set_offset(int);
    
    // Increments the offset
    void step();
    
    // Encodes character in forward direction
    char encode_forward(char);
    
    // Encodes character in backward direction
    char encode_backward(char);
    
    // Checks whether rotor is in the turnover position
    bool is_in_turnover_position();
    
    // Checks whether rotor can be used as reflector
    bool is_reflector();
    
private:
    int m_offset;
    std::string m_wiring;
    std::vector<int> m_turnovers;
    
    std::string known_wiring(rotor_wiring);
    std::vector<int> known_turnovers(rotor_wiring);
};

#endif /* defined(__Enigma__rotor__) */

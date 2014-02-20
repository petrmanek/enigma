//
//  tests.cpp
//  Enigma
//
//  Created by Petr Mánek on 20.02.14.
//  Copyright (c) 2014 TEEN, s.r.o. All rights reserved.
//

#include "tests.h"

void test_rotor() {
    // Encode the same letter few times over and
    // see if the rotor changes offset.
    
    Rotor r(w1);
    std::cout << r.encode(65);
    std::cout << r.encode(65);
    std::cout << r.encode(65);
    std::cout << r.encode(65);
    std::cout << "\n";
}

void test_rotor_custom_wiring() {
    // Same as test_rotor, but with ordinary
    // alphabetic wiring.
    
    Rotor r("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    std::cout << r.encode(65);
    std::cout << r.encode(65);
    std::cout << r.encode(65);
    std::cout << r.encode(65);
    std::cout << "\n";
}
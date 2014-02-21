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
    
    rotor r(w1);
    
    std::cout << r.encode_forward(65);
    r.step();
    std::cout << r.encode_forward(65);
    r.step();
    std::cout << r.encode_forward(65);
    r.step();
    std::cout << r.encode_forward(65);
    r.step();
    
    std::cout << "\n";
}

void test_rotor_custom_wiring() {
    // Same as test_rotor, but with ordinary
    // alphabetic wiring.
    
    rotor r("ABCDEFGHIJKLMNOPQRSTUVWXYZ", { });
    
    std::cout << r.encode_forward(65);
    r.step();
    std::cout << r.encode_forward(65);
    r.step();
    std::cout << r.encode_forward(65);
    r.step();
    std::cout << r.encode_forward(65);
    r.step();
    
    std::cout << "\n";
}

void test_rotor_forward_backward() {
    // Encode letter forward and backward
    // to test symetric cipher.
    
    rotor r(w1);
    
    std::cout << r.encode_forward(65);
    std::cout << r.encode_backward(65);
    
    std::cout << "\n";
}

void test_rotor_turnover() {
    // Encode few letters and check for
    // the turnover position.
    
    rotor r(w1);
    r.set_offset(14);
    
    std::cout << r.encode_forward(65) << " - offset: " << r.get_offset() << " - turnover: " << r.is_in_turnover_position() << "\n";
    r.step();
    std::cout << r.encode_forward(65) << " - offset: " << r.get_offset() << " - turnover: " << r.is_in_turnover_position() << "\n";
    r.step();
    std::cout << r.encode_forward(65) << " - offset: " << r.get_offset() << " - turnover: " << r.is_in_turnover_position() << "\n";
    r.step();
    std::cout << r.encode_forward(65) << " - offset: " << r.get_offset() << " - turnover: " << r.is_in_turnover_position() << "\n";
    r.step();
    
    std::cout << "\n";
}
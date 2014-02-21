//
//  main.cpp
//  Enigma
//
//  Created by Petr Mánek on 20.02.14.
//  Copyright (c) 2014 TEEN, s.r.o. All rights reserved.
//

#include <iostream>
#include "tests.h"

int main(int argc, const char * argv[])
{
    // Last test attempted
    test_rotor_forward_backward();

    return 0;
}

/*
 USAGE: enigma []
 
 PARAMETERS:
    -g --generate       Generates random key file.
 
 CONFIGURATIONS:
    -r --rotors         Sets number of rotors
*/
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
    test_machine_encode_decode();
    
    return 0;
}

/*
 USAGE: enigma []
 
 PARAMETERS:
    -g --generate       Generates random key file.
 
 CONFIGURATION:
    -r --rotors         Sets rotors in visible order (as seen on the physical machine, electrical current enters and exits the last rotor)
 
        1) Rotor name in brackets, all recognized rotor names:
                        - c1, c2, c3, (Commercial Enigma A, B - 1924)
                        - gr1, gr2, gr3, (German Railway, Rocket - 1941)
                        - k1, k2, k3, (Swiss K - 1939)
                        - w1, w2, w3, w4, w5, w6, w7, w8, (Military Rotors - 1930-1939)
                        - w_beta, w_gamma (Military Rotors - 1940-1942)
 
        2) Explicit rotor wiring (any permutation of 26 alphabetic letters ABCDEFGHIJKLMNOPQRSTUVWXYZ without fixed point)
 
        Additional:
            - to set turnover points, add indices 0-25 and / before the wiring (named rotors have turnover points already set up)
              (index n means that when the rotor is stepping from n to n+1, turnover will occur)
              e.g. 8/12/18/FKQHTLXOCBJSPDZRAMEWNIUYGV
 
            - to specify a starting offset, add : and index 0-25 after the name or wiring
              (starting offset 0 means "as-is")
              e.g. c1:23, FKQHTLXOCBJSPDZRAMEWNIUYGV:17
 
            - default turnover points are none (unless you're using a named rotor), default starting offset is 0
 
            - you can specify as many rotors as you like, but keep in mind that a lot of them might slow down the encryption/decryption process
 
            - separate all rotors by a comma without space
 
        Example usage: -r w8:19,k3,1/8/19/FKQHTLXOCBJSPDZRAMEWNIUYGV:3
*/
//
//  util.cpp
//  Enigma
//
//  Created by Petr Mánek on 21.02.14.
//  Copyright (c) 2014 TEEN, s.r.o. All rights reserved.
//

#include "util.h"

int mod(int a, int b) {
    return (a >= 0 || a % b == 0) ? (a % b) : (a + b * (int)(1 - a / b));
}
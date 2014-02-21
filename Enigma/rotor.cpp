//
//  rotor.cpp
//  Enigma
//
//  Created by Petr Mánek on 20.02.14.
//  Copyright (c) 2014 TEEN, s.r.o. All rights reserved.
//

#include <cctype>
#include <string>
#include <exception>
#include <algorithm>

#include "rotor.h"


#pragma mark - Constructors
rotor::rotor(rotor_wiring type) {
    // initialize instance vars
    m_offset = 0;
    m_turnovers = this->known_turnovers(type);
    m_wiring = this->known_wiring(type);
}

rotor::rotor(std::string wiring, std::vector<int> turnovers) {
    // check if the string has 26 chars
    if (wiring.length() != 26)
        throw std::runtime_error("Exactly 26 characters are expected in the string.");
    
    // check if the string is alphabetic
    for (int i = 0; i < wiring.length(); i++) {
        if (!isalpha(wiring[i]))
            throw std::runtime_error("Only alphabetic characters expected in the string.");
    }
    
    // todo: check if all letters are unique
    
    // normalize to upper case
    std::string normalized = wiring;
    std::transform(normalized.begin(), normalized.end(), normalized.begin(), ::toupper);
    
    // initialize instance vars
    m_offset = 0;
    m_turnovers = turnovers;
    m_wiring = normalized;
}


#pragma mark - Stepping
char rotor::get_offset() {
    return ASCII_START + this->m_offset;
}

void rotor::set_offset(int o) {
    this->m_offset = mod(o, 26);
}

void rotor::step() {
    this->set_offset(this->m_offset + 1);
}

bool rotor::is_in_turnover_position() {
    return std::find(this->m_turnovers.begin(), this->m_turnovers.end(), this->m_offset) != this->m_turnovers.end();
}


#pragma mark - Character encoding
char rotor::encode_forward(char c) {
    if (!isalpha(c))
        throw std::runtime_error("Lowercase or uppercase ASCII character expected.");
    
    char normalized = toupper(c);
    int offset = mod(this->m_offset + normalized - ASCII_START, 26);
    
    return this->m_wiring[offset];
}

char rotor::encode_backward(char c) {
    if (!isalpha(c))
        throw std::runtime_error("Lowercase or uppercase ASCII character expected.");
    
    char normalized = toupper(c);
    std::string::size_type index = this->m_wiring.find(normalized);
    
    if (index == std::string::npos)
        throw std::runtime_error("Invalid wiring. Character not found");
    
    return ASCII_START + mod((int)index - this->m_offset, 26);
}


#pragma mark - Known rotor configurations (from wikipedia)
std::vector<int> rotor::known_turnovers(rotor_wiring type) {
    switch (type) {
        case w1:
        {
            return { 16 };
        }
            
        case w2:
        {
            return { 4 };
        }
            
        case w3:
        {
            return { 21 };
        }
            
        case w4:
        {
            return { 9 };
        }
            
        case w5:
        {
            return { 25 };
        }
            
        case w6:
        case w7:
        case w8:
        {
            return { 12, 25 };
        }
            
        default:
        {
            return { };
        }
    }
}

std::string rotor::known_wiring(rotor_wiring type) {
    switch (type) {
        case c1:
        {
            return "DMTWSILRUYQNKFEJCAZBPGXOHV";
        }
            
        case c2:
        {
            return "HQZGPJTMOBLNCIFDYAWVEUSRKX";
        }
            
        case c3:
        {
            return "UQNTLSZFMREHDPXKIBVYGJCWOA";
        }
            
        case gr1:
        {
            return "JGDQOXUSCAMIFRVTPNEWKBLZYH";
        }
            
        case gr2:
        {
            return "NTZPSFBOKMWRCJDIVLAEYUXHGQ";
        }
            
        case gr3:
        {
            return "JVIUBHTCDYAKEQZPOSGXNRMWFL";
        }
            
        case gr_ukw:
        {
            return "QYHOGNECVPUZTFDJAXWMKISRBL";
        }
            
        case gr_etw:
        {
            return "QWERTZUIOASDFGHJKPYXCVBNML";
        }
            
        case k1:
        {
            return "PEZUOHXSCVFMTBGLRINQJWAYDK";
        }
            
        case k2:
        {
            return "ZOUESYDKFWPCIQXHMVBLGNJRAT";
        }
            
        case k3:
        {
            return "EHRVXGAOBQUSIMZFLYNWKTPDJC";
        }
            
        case k_ukw:
        {
            return "IMETCGFRAYSQBZXWLHKDVUPOJN";
        }
            
        case k_etw:
        {
            return "QWERTZUIOASDFGHJKPYXCVBNML";
        }
            
        case w1:
        {
            return "EKMFLGDQVZNTOWYHXUSPAIBRCJ";
        }
            
        case w2:
        {
            return "AJDKSIRUXBLHWTMCQGZNPYFVOE";
        }
            
        case w3:
        {
            return "BDFHJLCPRTXVZNYEIWGAKMUSQO";
        }
            
        case w4:
        {
            return "ESOVPZJAYQUIRHXLNFTGKDCMWB";
        }
            
        case w5:
        {
            return "VZBRGITYUPSDNHLXAWMJQOFECK";
        }
            
        case w6:
        {
            return "JPGVOUMFYQBENHZRDKASXLICTW";
        }
            
        case w7:
        {
            return "NZJHGRCXMYSWBOUFAIVLPEKQDT";
        }
            
        case w8:
        {
            return "FKQHTLXOCBJSPDZRAMEWNIUYGV";
        }
            
        case w_beta:
        {
            return "LEYJVCNIXWPBQMDRTAKZGFUHOS";
        }
            
        case w_gamma:
        {
            return "FSOKANUERHMBTIYCWLQPZXVGJD";
        }
            
        case w_ra:
        {
            return "EJMZALYXVBWFCRQUONTSPIKHGD";
        }
            
        case w_rb:
        {
            return "YRUHQSLDPXNGOKMIEBFZCWVJAT";
        }
            
        case w_rc:
        {
            return "FVPJIAOYEDRZXWGCTKUQSBNMHL";
        }
            
        case w_rbt:
        {
            return "ENKQAUYWJICOPBLMDXZVFTHRGS";
        }
            
        case w_rct:
        {
            return "RDOBJNTKVEHMLFCWZAXGYIPSUQ";
        }
            
        case w_etw:
        {
            return "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        }
            
        default:
        {
            throw std::runtime_error("Unknown configuration.");
        }
    }
}
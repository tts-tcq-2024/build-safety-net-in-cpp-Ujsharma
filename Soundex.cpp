#include "Soundex.h"
#include <cctype>
#include<string>

char getSoundexCode(char c) {
    c = toupper(c);
    if (c == 'B' || c == 'F' || c == 'P' || c == 'V') {
        return '1';
    } else if (c == 'C' || c == 'G' || c == 'J' || c == 'K' || c == 'Q' || c == 'S' || c == 'X' || c == 'Z') {
        return '2';
    } else if (c == 'D' || c == 'T') {
        return '3';
    } else if (c == 'L') {
        return '4';
    } else if (c == 'M' || c == 'N') {
        return '5';
    } else if (c == 'R') {
        return '6';
    } else {
        return '0'; // For A, E, I, O, U, H, W, Y and any other characters
    }
}

std::string generateSoundex(const std::string& name) {
    if (name.empty()) return "";

    std::string soundex; // Initialize soundex as an empty string
    char prevCode = '\0'; // Initialize prevCode with null character (assuming prevCode is a char variable)
    size_t i = 1; // Initialize index i with 1

    while (i < name.length()) {
        char code = getSoundexCode(name[i]);

        if (soundex.length() < 4) {
            if (code != '0' && code != prevCode) {
                soundex += code;
                prevCode = code;
            }
            else {
                soundex += '0';
            }
        }
        
        i++; // Move to the next character in name
    }

    // Pad soundex with zeros if its length is less than 4
    while (soundex.length() < 4) {
        soundex += '0';
    }

    return soundex;
}



    
    

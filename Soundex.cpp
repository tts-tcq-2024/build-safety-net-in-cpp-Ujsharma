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

    std::string soundex(1, toupper(name[0]));
    char prevCode = getSoundexCode(name[0]);

    for (size_t i = 1; i < name.length(); ++i) {
        char code = getSoundexCode(name[i]);
       if (soundex.length() < 4){
          if (code != '0' && code != prevCode) {
             soundex += code;
             prevCode = code;}
       }
       if (soundex.length() < 4) {
        soundex += '0';
    }
    return soundex;
}
}

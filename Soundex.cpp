#include "Soundex.h"
#include <cctype>
#include<string>
#include <unordered_map>

char getSoundexCode(char c) {
    static const std::unordered_map<char, char> soundexMap {
        {'B', '1'}, {'F', '1'}, {'P', '1'}, {'V', '1'},
        {'C', '2'}, {'G', '2'}, {'J', '2'}, {'K', '2'},
        {'Q', '2'}, {'S', '2'}, {'X', '2'}, {'Z', '2'},
        {'D', '3'}, {'T', '3'},
        {'L', '4'},
        {'M', '5'}, {'N', '5'},
        {'R', '6'}
    };
 
    c = std::toupper(c);
    auto it = soundexMap.find(c);
    if (it != soundexMap.end()) {
        return it->second;
    }
    return '0'; // Default case
}

std::string generateSoundex(const std::string& name) {
    if (name.empty()) return "";

    std::string soundex;
    char prevCode = '\0';
    size_t i = 0;

    // Iterate over each character of the name
    if (i < name.length()) {
        char code = getSoundexCode(name[i]);

        // Ensure soundex length does not exceed 4 characters
        if (soundex.length() < 4) {
            if (code != '0' && code != prevCode) {
                soundex += code;
                prevCode = code;
            } else {
                soundex += '0'; // Pad with '0' for non-matching or duplicate codes
            }
        }

        ++i; // Move to the next character
    }

    // Pad with '0' if soundex is less than 4 characters
    while (soundex.length() < 4) {
        soundex += '0';
    }
    return soundex;
}

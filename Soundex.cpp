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

std::string generateSoundexCodes(const std::string& name) {
    std::string soundex;
    char prevCode = '\0';

    for (char c : name) {
        char code = getSoundexCode(c);

        if (soundex.length() < 4) {
            if (code != '0' && code != prevCode) {
                soundex += code;
                prevCode = code;
            } else if (soundex.empty() || soundex.back() != '0') {
                soundex += '0';
            }
        } else {
            break; 
        }
    }

    return soundex;
}

std::string padSoundex(const std::string& soundex) {
    std::string paddedSoundex = soundex;
    paddedSoundex.resize(4, '0'); // Pad with '0' if soundex is less than 4 characters
    return paddedSoundex;
}

std::string generateSoundex(const std::string& name) {
    if (name.empty()) return "0000"; // Return early for empty strings

    std::string soundex = generateSoundexCodes(name);
    return padSoundex(soundex);
}


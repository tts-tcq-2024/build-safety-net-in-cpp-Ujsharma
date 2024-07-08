#include "Soundex.h"

const std::unordered_map<char, char> soundexMap {
    {'B', '1'}, {'F', '1'}, {'P', '1'}, {'V', '1'},
    {'C', '2'}, {'G', '2'}, {'J', '2'}, {'K', '2'},
    {'Q', '2'}, {'S', '2'}, {'X', '2'}, {'Z', '2'},
    {'D', '3'}, {'T', '3'},
    {'L', '4'},
    {'M', '5'}, {'N', '5'},
    {'R', '6'}
};

char getSoundexCode(char c) {
    c = std::toupper(c);
    auto it = soundexMap.find(c);
    if (it != soundexMap.end()) {
        return it->second;
    }
    return '0'; // Default case
}

bool SoundexLengthCheck(const std::string& soundex) {
    return soundex.length() < 4;
}

bool SoundexCodeCheck(char code, char prevCode) {
    return (code != '0' && code != prevCode);
}

std::string generateSoundex(const std::string& name) {
    if (name.empty()) return "";

    std::string soundex;
    soundex += std::toupper(name[0]);
    char prevCode = getSoundexCode(name[0]);

    for (char c : name.substr(1)) {
        char code = getSoundexCode(c);
        if (code != '0' && SoundexCodeCheck(code, prevCode)) {
            soundex += code;
            prevCode = code;
        } else {
            soundex += '0';
        }
        if (soundex.length() >= 4) break; // Break if soundex reaches 4 characters
    }

    soundex += std::string(4 - soundex.length(), '0'); // Pad with '0' if soundex is less than 4 characters
    return soundex.substr(0, 4); // Ensure the result is exactly 4 characters long
}

std::string padSoundex(const std::string& soundex) {
    std::string paddedSoundex = soundex;
    paddedSoundex.resize(4, '0'); // Pad with '0' if soundex is less than 4 characters
    return paddedSoundex;
}

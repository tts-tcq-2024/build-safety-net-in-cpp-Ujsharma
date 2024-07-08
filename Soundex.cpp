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

bool SoundexLengthCheck(const std::string& soundex) {
    return soundex.length() < 4;
}

bool SoundexCodeCheck(const char code, char prevCode) {
    return (code != '0' && code != prevCode);
}

std::string SoundexIncrement(const std::string& soundex, char code, char prevCode) {
    size_t i = 1;
if (SoundexLengthCheck==true){
    char code = getSoundexCode(name[i]);}
    if(SoundexCodeCheck(code, prevCode)==true){
        i++;
        soundex += code;
        prevCode = code;}
else {soundex += '0';}}
    
std::string generateSoundex(const std::string& name) {
    if (name.empty()) return "";

    std::string soundex(1, toupper(name[0]));
    char prevCode = getSoundexCode(name[0]);
    SoundexIncrement(soundex,code,prevCode);
    return soundex;
}

std::string padSoundex(const std::string& soundex) {
    std::string paddedSoundex = soundex;
    paddedSoundex.resize(4, '0'); // Pad with '0' if soundex is less than 4 characters
    return paddedSoundex;
}




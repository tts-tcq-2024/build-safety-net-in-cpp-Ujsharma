#ifndef SOUNDEX_H
#define SOUNDEX_H

#include <string>
#include <unordered_map>

extern const std::unordered_map<char, char> soundexMap;

char getSoundexCode(char c);
bool SoundexLengthCheck(const std::string& soundex);
bool SoundexCodeCheck(char code, char prevCode);
std::string generateSoundex(const std::string& name);
std::string padSoundex(const std::string& soundex);

#endif // SOUNDEX_H

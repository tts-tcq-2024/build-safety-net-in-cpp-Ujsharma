#include <iostream>
#include <string>
#include <cctype>
#include <cstring> // Include for strchr function

// Function to convert a character to uppercase
char toUpper(char c) {
    return std::toupper(static_cast<unsigned char>(c));
}

// Function to map a character to its Soundex code
char mapToSoundexCode(char c, bool isConsonant) {
    c = toUpper(c);
    if (isConsonant) {
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
        }
    }
    return '0'; // For vowels and other characters
}

// Function to determine if a character is a consonant
bool isConsonant(char c) {
    c = toUpper(c);
    return (c >= 'A' && c <= 'Z' && strchr("AEIOUHWY", c) == nullptr); // Use strchr in global namespace
}

// Function to generate Soundex code for a given name
std::string generateSoundex(const std::string& name) {
    if (name.empty()) return "";

    std::string soundex;
    char prevCode = '\0';

    for (size_t i = 0; i < name.length(); ++i) {
        char code = mapToSoundexCode(name[i], isConsonant(name[i]));
        
        if (soundex.length() < 4) {
            if (code != '0' && code != prevCode) {
                soundex += code;
                prevCode = code;
            }
            else {
                soundex += '0';
            }
        }
    }

    while (soundex.length() < 4) {
        soundex += '0';
    }

    return soundex;
}

int main() {
    std::string name = "Johnson";
    std::string soundex = generateSoundex(name);
    std::cout << "Soundex code for " << name << " is: " << soundex << std::endl;
    
    return 0;
}

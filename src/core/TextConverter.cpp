#include <vector>
#include <string>
#include "TranslationResult.h"
#include <unordered_map>


class ITextConverter {
public:
    virtual ~ITextConverter() = default;
    

    virtual TranslationResult convert(const std::string& text) = 0; 
};


class MorseConverter : public ITextConverter {
private:
    std::unordered_map<char, std::string> morseAlphabet = {
        {'A', ".-"},    {'B', "-..."},  {'C', "-.-."},  {'D', "-.."},
        {'E', "."},     {'F', "..-."},  {'G', "--."},   {'H', "...."},
        {'I', ".."},    {'J', ".---"},  {'K', "-.-"},   {'L', ".-.."},
        {'M', "--"},    {'N', "-."},    {'O', "---"},   {'P', ".--."},
        {'Q', "--.-"},  {'R', ".-."},   {'S', "..."},   {'T', "-"},
        {'U', "..-"},   {'V', "...-"},  {'W', ".--"},   {'X', "-..-"},
        {'Y', "-.--"},  {'Z', "--.."},
        
        {'1', ".----"}, {'2', "..---"}, {'3', "...--"}, {'4', "....-"},
        {'5', "....."}, {'6', "-...."}, {'7', "--..."}, {'8', "---.."},
        {'9', "----."}, {'0', "-----"},
        
        {' ', " / "}
    };

public:
    TranslationResult convert(const std::string& text) override {
        std::string convertedText = "";
        std::vector<std::string> warnings;

        for (char c : text) {
            char upperChar = std::toupper(c);
            auto it = morseAlphabet.find(upperChar);
            
            if (it != morseAlphabet.end()) {
                convertedText += it->second;

                if (upperChar != ' ') {
                    convertedText += " ";
                }
            } else {
                warnings.push_back("Символ '" + std::string(1, c) + "' проігноровано.");
            }
        }

        if (!convertedText.empty() && convertedText.back() == ' ') {
            convertedText.pop_back();
        }

        return TranslationResult(convertedText, warnings, warnings.empty());
    }
};

class BrailleConverter : public ITextConverter {
private:
    std::unordered_map<char, std::string> brailleAlphabet = {
        {'A', "⠁"}, {'B', "⠃"}, {'C', "⠉"}, {'D', "⠙"},
        {'E', "⠑"}, {'F', "⠋"}, {'G', "⠛"}, {'H', "⠓"},
        {'I', "⠊"}, {'J', "⠚"}, {'K', "⠅"}, {'L', "⠇"},
        {'M', "⠍"}, {'N', "⠝"}, {'O', "⠕"}, {'P', "⠏"},
        {'Q', "⠟"}, {'R', "⠗"}, {'S', "⠎"}, {'T', "⠞"},
        {'U', "⠥"}, {'V', "⠧"}, {'W', "⠺"}, {'X', "⠭"},
        {'Y', "⠽"}, {'Z', "⠵"},

        {'1', "⠼⠁"}, {'2', "⠼⠃"}, {'3', "⠼⠉"}, {'4', "⠼⠙"},
        {'5', "⠼⠑"}, {'6', "⠼⠋"}, {'7', "⠼⠛"}, {'8', "⠼⠓"},
        {'9', "⠼⠊"}, {'0', "⠼⠚"},
        
        {' ', " "}
    };

public: 
    TranslationResult convert(const std::string& text) override {
        std::string convertedText = "";
        std::vector<std::string> warnings;

        for (char c : text) {
            char upperChar = std::toupper(c);
            auto it = brailleAlphabet.find(upperChar);
            
            if (it != brailleAlphabet.end()) {

                convertedText += it->second;
            } else {
                warnings.push_back("Символ '" + std::string(1, c) + "' проігноровано.");
            }
        }

        return TranslationResult(convertedText, warnings, warnings.empty());
    }
};






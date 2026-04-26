#include "TextConverter.h"

#include <cctype>
#include <vector>

MorseConverter::MorseConverter()
    : morseAlphabet({
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
      }) {}

TranslationResult MorseConverter::convert(const std::string& text) {
    std::string convertedText;
    std::vector<std::string> warnings;

    for (char c : text) {
        const char upperChar = static_cast<char>(std::toupper(static_cast<unsigned char>(c)));
        const auto it = morseAlphabet.find(upperChar);

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

BrailleConverter::BrailleConverter()
    : brailleAlphabet({
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
      }) {}

TranslationResult BrailleConverter::convert(const std::string& text) {
    std::string convertedText;
    std::vector<std::string> warnings;

    for (char c : text) {
        const char upperChar = static_cast<char>(std::toupper(static_cast<unsigned char>(c)));
        const auto it = brailleAlphabet.find(upperChar);

        if (it != brailleAlphabet.end()) {
            convertedText += it->second;
        } else {
            warnings.push_back("Символ '" + std::string(1, c) + "' проігноровано.");
        }
    }

    return TranslationResult(convertedText, warnings, warnings.empty());
}






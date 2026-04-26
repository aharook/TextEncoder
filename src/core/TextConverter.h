#ifndef TEXTCONVERTER_H
#define TEXTCONVERTER_H

#include <string>
#include <unordered_map>
#include "TranslationResult.h"

class ITextConverter {
public:
    virtual ~ITextConverter() = default;
    virtual TranslationResult convert(const std::string& text) = 0;
};

class MorseConverter : public ITextConverter {
private:
    std::unordered_map<char, std::string> morseAlphabet;

public:
    MorseConverter();
    TranslationResult convert(const std::string& text) override;
};

class BrailleConverter : public ITextConverter {
private:
    std::unordered_map<char, std::string> brailleAlphabet;

public:
    BrailleConverter();
    TranslationResult convert(const std::string& text) override;
};

#endif



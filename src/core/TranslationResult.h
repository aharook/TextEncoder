#ifndef TRANSLATIONRESULT_H
#define TRANSLATIONRESULT_H

#include <string>
#include <vector>

class TranslationResult {

    std::string converted_text;
    std::vector<std::string> Warnings;
    bool IsSucces;

    public:

    TranslationResult( std::string converted_text, std::vector<std::string> Warnings, bool IsSucces)
    : converted_text(converted_text), Warnings(Warnings), IsSucces(IsSucces) {};

    std::string Get_converted_text(){return converted_text;}

    std::vector<std::string> get_Warnings(){return Warnings;}

    
};

#endif
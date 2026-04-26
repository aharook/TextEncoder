#ifndef TRANSLATIONRESULT_H
#define TRANSLATIONRESULT_H

#include <string>
#include <vector>

class TranslationResult {

    std::string converted_text;
    std::vector<std::string> Warnings;
    bool IsSuccess;

    public:

    TranslationResult( std::string converted_text, std::vector<std::string> Warnings, bool IsSuccess)
    : converted_text(converted_text), Warnings(Warnings), IsSuccess(IsSuccess) {};

    std::string Get_converted_text() const {return converted_text;}

    std::vector<std::string> get_Warnings() const {return Warnings;}   
    bool GetIsSuccess() const { return IsSuccess; }
};

#endif
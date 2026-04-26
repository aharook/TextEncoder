#ifndef TRANSLATIONREQUEST_H
#define TRANSLATIONREQUEST_H

#include <string>
#include "convertType.h"

class TranslationRequest {
    std::string Text;
    Convert_type Type;

public:
    TranslationRequest(std::string Text, Convert_type Type);

    std::string GetText() const { return Text; }
    
    Convert_type GetType() const { return Type; }
};

#endif
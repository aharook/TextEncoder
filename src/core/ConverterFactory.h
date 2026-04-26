#ifndef CONVERTERFACTORY_H
#define CONVERTERFACTORY_H

#include <memory>

#include "TextConverter.h"

class ConverterFactory {
public:
    static std::unique_ptr<ITextConverter> CreateMorse();
    static std::unique_ptr<ITextConverter> CreateBraille();
};

#endif
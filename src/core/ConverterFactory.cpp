#include "ConverterFactory.h"

std::unique_ptr<ITextConverter> ConverterFactory::CreateMorse() {
    return std::make_unique<MorseConverter>();
}

std::unique_ptr<ITextConverter> ConverterFactory::CreateBraille() {
    return std::make_unique<BrailleConverter>();
}
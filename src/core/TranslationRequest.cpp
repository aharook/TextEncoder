#include "TranslationRequest.h"

#include <utility>

TranslationRequest::TranslationRequest(std::string Text, Convert_type Type)
    : Text(std::move(Text)), Type(Type) {}

#ifndef ICONVERTERFACTORY_H
#define ICONVERTERFACTORY_H

#include <memory>

#include "TextConverter.h"
#include "convertType.h"

class IConverterFactory {
public:
    virtual ~IConverterFactory() = default;

    virtual std::unique_ptr<ITextConverter> Create() const = 0;
    virtual Convert_type GetConfiguredType() const = 0;
};

#endif
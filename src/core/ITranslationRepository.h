#ifndef ITRANSLATIONREPOSITORY_H
#define ITRANSLATIONREPOSITORY_H

#include "TranslationRecord.h"
#include <vector>

class ITranslationRepository {
public:

    virtual ~ITranslationRepository() = default;

    virtual void Save(const TranslationRecord& record) = 0;

    virtual std::vector<TranslationRecord> GetAll() const = 0;
    
    virtual void Clear() = 0;
};

#endif
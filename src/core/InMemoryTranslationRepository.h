#ifndef INMEMORYTRANSLATIONREPOSITORY_H
#define INMEMORYTRANSLATIONREPOSITORY_H

#include "ITranslationRepository.h"
#include <vector>

class InMemoryTranslationRepository : public ITranslationRepository {
private:
    std::vector<TranslationRecord> _records;

public:

    void Save(const TranslationRecord& record) override {
        _records.push_back(record);
    }

    std::vector<TranslationRecord> GetAll() const override {
        return _records;
    }

    void Clear() override {
        _records.clear();
    }
};

#endif
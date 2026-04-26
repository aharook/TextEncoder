#ifndef TRANSLATIONAPPSERVICE_H
#define TRANSLATIONAPPSERVICE_H

#include <map>
#include <stdexcept>

#include "ConverterFactory.h"
#include "ITranslationRepository.h"
#include "TranslationRecord.h"
#include "TranslationRequest.h"
#include "TranslationResult.h"


class TranslationAppService {
private:
    ITranslationRepository& repository;

public:
    explicit TranslationAppService(ITranslationRepository& repository)
        : repository(repository) {}

    TranslationResult execute(const TranslationRequest& request) {
        using ConverterCreator = std::unique_ptr<ITextConverter> (*)();
        static const std::map<Convert_type, ConverterCreator> kConverterCreators = {
            {Convert_type::Morse, ConverterFactory::CreateMorse},
            {Convert_type::Braille, ConverterFactory::CreateBraille}
        };

        const auto creatorIt = kConverterCreators.find(request.GetType());
        if (creatorIt == kConverterCreators.end()) {
            throw std::invalid_argument("Unsupported conversion type.");
        }

        std::unique_ptr<ITextConverter> converter = creatorIt->second();

        TranslationResult result = converter->convert(request.GetText());
        TranslationRecord record(request, result);
        repository.Save(record);

        return result;
    }
};

#endif

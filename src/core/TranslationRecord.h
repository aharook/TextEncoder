#ifndef TRANSLATIONRECORD_H
#define TRANSLATIONRECORD_H

#include <string>
#include "TranslationRequest.h"
#include "TranslationResult.h"
#include <chrono>

class TranslationRecord {
private:
    TranslationRequest request;
    TranslationResult result;
    std::chrono::system_clock::time_point savedAt;

public:

    TranslationRecord(const TranslationRequest& request, const TranslationResult& result)
        : request(request), result(result) 
    {
        savedAt = std::chrono::system_clock::now();
    }
    
    TranslationRequest GetRequest() const { return request; }
    TranslationResult GetResult() const { return result; }
    std::chrono::system_clock::time_point GetSavedAt() const { return savedAt; }
};

#endif
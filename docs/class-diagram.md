```mermaid
classDiagram
    class FormatType {
        <<enumeration>>
        MORSE
        BRAILLE
    }

    class TranslationRequest {
        +String Text
        +FormatType TargetFormat
        +TranslationRequest(text, format)
    }

    class TranslationResult {
        +String ConvertedText
        +List~String~ Warnings
        +Boolean IsSuccess
    }

    class TranslationRecord {
        +Guid Id
        +TranslationRequest Request
        +TranslationResult Result
        +DateTime CreatedAt
    }

    class ITextConverter {
        <<interface>>
        +Convert(text: String) TranslationResult
    }

    class MorseConverter {
        -Dictionary~char, string~ alphabet
        +Convert(text: String) TranslationResult
    }

    class BrailleConverter {
        -Dictionary~char, string~ alphabet
        +Convert(text: String) TranslationResult
    }

    class ITranslationRepository {
        <<interface>>
        +Save(record: TranslationRecord)
        +GetAll() List~TranslationRecord~
    }

    class InMemoryTranslationRepository {
        -List~TranslationRecord~ _storage
    }

    class TranslationAppService {
        -ITranslationRepository _repository
        -ConverterFactory _factory
        +ExecuteTranslation(request: TranslationRequest) TranslationResult
    }

    ITextConverter <|.. MorseConverter
    ITextConverter <|.. BrailleConverter
    ITranslationRepository <|.. InMemoryTranslationRepository
    TranslationAppService --> ITranslationRepository
    TranslationAppService --> ITextConverter
    TranslationRecord *-- TranslationRequest
    TranslationRecord *-- TranslationResult
    ```
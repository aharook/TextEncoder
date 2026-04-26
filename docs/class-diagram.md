```mermaid
classDiagram
    class Convert_type {
        <<enumeration>>
        Morse
        Braille
    }

    class TranslationRequest {
        -String Text
        -Convert_type Type
        +TranslationRequest(text: String, type: Convert_type)
        +GetText() String
        +GetType() Convert_type
    }

    class TranslationResult {
        -String converted_text
        -List~String~ Warnings
        -Boolean IsSuccess
        +TranslationResult(text, warnings, success)
        +Get_converted_text() String
        +get_Warnings() List~String~
        +GetIsSuccess() Boolean
    }

    class TranslationRecord {
        -TranslationRequest request
        -TranslationResult result
        -time_point savedAt
        +TranslationRecord(request, result)
        +GetRequest() TranslationRequest
        +GetResult() TranslationResult
        +GetSavedAt() time_point
    }
namespace Strategy {
    class ITextConverter {
        <<interface>>
        +convert(text: String) TranslationResult
    }

    class MorseConverter {
        -Map morseAlphabet
        +convert(text: String) TranslationResult
    }

    class BrailleConverter {
        -Map brailleAlphabet
        +convert(text: String) TranslationResult
    }
}

namespace Repository {

    class ITranslationRepository {
        <<interface>>
        +Save(record: TranslationRecord)
        +GetAll() List~TranslationRecord~
        +Clear()
    }

    class InMemoryTranslationRepository {
        -List~TranslationRecord~ _records
        +Save(record: TranslationRecord)
        +GetAll() List~TranslationRecord~
        +Clear()
    }
}
namespace Factory {
    class ConverterFactory {
        +Create(type: Convert_type)$ ITextConverter
    }
}
    class TranslationAppService {
        -ITranslationRepository _repository
        +TranslationAppService(repository: ITranslationRepository)
        +ExecuteTranslation(request: TranslationRequest) TranslationResult
    }

    ITextConverter <|.. MorseConverter
    ITextConverter <|.. BrailleConverter 
    ITranslationRepository <|.. InMemoryTranslationRepository 

    TranslationRequest --> Convert_type 
    TranslationRecord *-- TranslationRequest 
    TranslationRecord *-- TranslationResult 

    ConverterFactory ..> ITextConverter 
    ConverterFactory ..> Convert_type 

    TranslationAppService --> ITranslationRepository 
    TranslationAppService ..> ConverterFactory 
    TranslationAppService ..> TranslationRequest 
    TranslationAppService ..> TranslationRecord
    ```
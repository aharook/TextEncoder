#include <gtest/gtest.h>

#include "ConverterFactory.h"
#include "InMemoryTranslationRepository.h"
#include "TranslationAppService.h"

TEST(ConverterFactoryTests, CreateMorseReturnsMorseConverter) {
    std::unique_ptr<ITextConverter> converter = ConverterFactory::CreateMorse();

    ASSERT_NE(converter, nullptr);
    EXPECT_NE(dynamic_cast<MorseConverter*>(converter.get()), nullptr);
}

TEST(ConverterFactoryTests, CreateBrailleReturnsBrailleConverter) {
    std::unique_ptr<ITextConverter> converter = ConverterFactory::CreateBraille();

    ASSERT_NE(converter, nullptr);
    EXPECT_NE(dynamic_cast<BrailleConverter*>(converter.get()), nullptr);
}

TEST(TranslationAppServiceTests, ExecuteUsesMorseStrategyAndSavesRecord) {
    InMemoryTranslationRepository repository;
    TranslationAppService service(repository);

    const TranslationRequest request("SOS", Convert_type::Morse);
    const TranslationResult result = service.execute(request);

    EXPECT_EQ(result.Get_converted_text(), "... --- ...");

    const auto records = repository.GetAll();
    ASSERT_EQ(records.size(), 1u);
    EXPECT_EQ(records[0].GetRequest().GetType(), Convert_type::Morse);
    EXPECT_EQ(records[0].GetResult().Get_converted_text(), "... --- ...");
}

TEST(TranslationAppServiceTests, ExecuteUsesBrailleStrategyAndSavesRecord) {
    InMemoryTranslationRepository repository;
    TranslationAppService service(repository);

    const TranslationRequest request("AB12", Convert_type::Braille);
    const TranslationResult result = service.execute(request);

    EXPECT_EQ(result.Get_converted_text(), "⠁⠃⠼⠁⠼⠃");

    const auto records = repository.GetAll();
    ASSERT_EQ(records.size(), 1u);
    EXPECT_EQ(records[0].GetRequest().GetType(), Convert_type::Braille);
    EXPECT_EQ(records[0].GetResult().Get_converted_text(), "⠁⠃⠼⠁⠼⠃");
}

TEST(TextConverterTests, MorseConvertAddsWarningForUnsupportedCharacter) {
    MorseConverter converter;

    const TranslationResult result = converter.convert("A@");

    EXPECT_EQ(result.Get_converted_text(), ".-");
    EXPECT_EQ(result.get_Warnings().size(), 1u);
}

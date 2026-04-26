cmake_minimum_required(VERSION 3.20)

project(TextEncoder LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(textencoder_core
	src/core/TextConverter.cpp
	src/core/ConverterFactory.cpp
	src/core/TranslationRequest.cpp
)

target_include_directories(textencoder_core
	PUBLIC
		src/core
)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

file(GLOB_RECURSE TEST_SOURCES CONFIGURE_DEPENDS tests/*.cpp)

if(TEST_SOURCES)
	add_executable(textencoder_tests ${TEST_SOURCES})
	target_link_libraries(textencoder_tests PRIVATE textencoder_core GTest::gtest_main)
	include(GoogleTest)
	gtest_discover_tests(textencoder_tests)
endif()

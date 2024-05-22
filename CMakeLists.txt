cmake_minimum_required(VERSION 3.10)
project(BigIntImplement VERSION 1.0.0 LANGUAGES CXX)

include(CTest)
enable_testing()

# Google Test
set(CMAKE_BUILD_TYPE "Debug")
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Find all source files
file(GLOB_RECURSE SOURCES src/*.cpp)
add_library(BigInt ${SOURCES})  # Create a library target (optional)
target_compile_features(BigInt PUBLIC cxx_std_17)
target_include_directories(BigInt PUBLIC include)

# Find all test files
file(GLOB_RECURSE TEST_SOURCES test/*.cpp)
add_executable(test_bigInt ${TEST_SOURCES})
target_compile_features(test_bigInt PUBLIC cxx_std_17)
target_link_libraries(test_bigInt BigInt GTest::gtest_main)  

# Link to BigInt library (if created)
target_include_directories(test_bigInt PUBLIC include)

include(GoogleTest)
gtest_discover_tests(test_bigInt)

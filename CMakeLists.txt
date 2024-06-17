cmake_minimum_required(VERSION 3.10)
project(BigIntImplement VERSION 1.0.0 LANGUAGES CXX)

include(CTest)
enable_testing()

# Google Test
set(CMAKE_BUILD_TYPE "Debug")
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG v1.14.0
)
# set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)


# Build BigInt library
file(GLOB_RECURSE SOURCES src/*.cpp)
add_library(BigInt ${SOURCES})  # Create a library target (optional)
target_compile_features(BigInt PUBLIC cxx_std_17)
target_compile_options(BigInt PRIVATE -Wall -Werror -pedantic -O3 -ffast-math)
target_include_directories(BigInt PUBLIC include)

# Build test executable
file(GLOB_RECURSE TEST_SOURCES test/*.cc)
add_executable(test_bigInt ${TEST_SOURCES})
target_compile_features(test_bigInt PUBLIC cxx_std_17)
target_link_libraries(test_bigInt BigInt GTest::gtest_main)  
target_include_directories(test_bigInt PUBLIC include)

# Build stdio executable - test the library
add_executable(app_bigInt app/app_bigint.cpp)
target_link_libraries(app_bigInt BigInt)
target_include_directories(app_bigInt PUBLIC include)
target_compile_features(app_bigInt PUBLIC cxx_std_17)

include(GoogleTest)
gtest_discover_tests(test_bigInt)





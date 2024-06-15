cmake_minimum_required(VERSION 3.10)
project(BigIntImplement VERSION 1.0.0 LANGUAGES CXX)
# SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -xc++ -Wall -Wunused-variable -Wshadow")

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


# Find all source files
file(GLOB_RECURSE SOURCES src/*.cpp)
add_library(BigInt ${SOURCES})  # Create a library target (optional)
target_compile_features(BigInt PUBLIC cxx_std_17)
target_include_directories(BigInt PUBLIC include)

# Find all test files
file(GLOB_RECURSE TEST_SOURCES test/*.cc)
add_executable(test_bigInt ${TEST_SOURCES})
target_compile_features(test_bigInt PUBLIC cxx_std_17)
target_link_libraries(test_bigInt BigInt GTest::gtest_main)  

# Link to BigInt library (if created)
target_include_directories(test_bigInt PUBLIC include)

# Add main executable and link to BigInt library
add_executable(bigIntMain app/main.cpp)
target_link_libraries(bigIntMain BigInt)
target_include_directories(bigIntMain PUBLIC include)
target_compile_features(bigIntMain PUBLIC cxx_std_17)

include(GoogleTest)
gtest_discover_tests(test_bigInt)





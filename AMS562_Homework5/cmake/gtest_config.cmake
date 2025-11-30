# cmake/gtest_config.cmake
# ------------------------------------------------------------------
# Download and Build GTest using FetchContent
# ------------------------------------------------------------------
include(FetchContent)

FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.15.2
)

# Prevent overriding the parent project's compiler/linker settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Include GTest Headers
include_directories(${googletest_SOURCE_DIR}/googletest/include)
set(GTEST_LIBS gtest gtest_main)
list(REMOVE_DUPLICATES GTEST_LIBS)

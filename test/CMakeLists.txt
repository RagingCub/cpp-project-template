include(GoogleTest)

FetchContent_MakeAvailable(googletest_target)

set(GTEST_LIBRARIES gtest gmock gtest_main gmock_main pthread)

add_subdirectory(infrastructure)

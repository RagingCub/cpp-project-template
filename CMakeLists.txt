cmake_minimum_required(VERSION 3.14)
project(cpp-project-template)

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)

FetchContent_Declare(mariadbpp-target
        GIT_REPOSITORY "https://github.com/viaduck/mariadbpp")

FetchContent_Declare(sentry-native-target
        GIT_REPOSITORY "https://github.com/getsentry/sentry-native"
        GIT_TAG "0.3.4")

FetchContent_Declare(googletest
        GIT_REPOSITORY "https://github.com/google/googletest.git"
        GIT_TAG "release-1.10.0")

FetchContent_MakeAvailable(mariadbpp-target sentry-native-target)

option(BUILD_TESTING "build unit tests" ON)

include_directories(/usr/include/mariadb)
include_directories(${CMAKE_CURRENT_BINARY_DIR}/extern/include)
link_directories(${CMAKE_CURRENT_BINARY_DIR}/extern/lib)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

add_subdirectory(src)
if (BUILD_TESTING)
    enable_testing()

    add_subdirectory(test)
endif ()

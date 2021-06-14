include(FetchContent)

# BSD-3-Clause License
FetchContent_Declare(googletest_target
        GIT_REPOSITORY "https://github.com/google/googletest.git"
        GIT_TAG "release-1.11.0")

# BSL-1.0 License
FetchContent_Declare(mariadbpp_target
        GIT_REPOSITORY "https://github.com/viaduck/mariadbpp.git"
        GIT_TAG "v1.0.0")

# MIT License
FetchContent_Declare(sentry-native_target
        GIT_REPOSITORY "https://github.com/getsentry/sentry-native.git"
        GIT_TAG "0.3.4")

FetchContent_MakeAvailable(mariadbpp_target sentry-native_target)

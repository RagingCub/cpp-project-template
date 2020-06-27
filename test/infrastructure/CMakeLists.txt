set(INFRASTRUCTURE_TEST_FILES sentry/sentry_logger_test.cpp)

include_directories(${PROJECT_SOURCE_DIR}/include/domain)
include_directories(${PROJECT_SOURCE_DIR}/include/infrastructure)

add_executable(infrastructure_test ${INFRASTRUCTURE_TEST_FILES})
target_link_libraries(infrastructure_test infrastructure ${GTEST_LIBRARIES})

gtest_discover_tests(infrastructure_test)

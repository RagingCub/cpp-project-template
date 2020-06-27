set(INFRASTRUCTURE_SRC_FILES sentry/sentry_proxy.cpp sentry/sentry_logger.cpp)

include_directories(${PROJECT_SOURCE_DIR}/include/domain)
include_directories(${PROJECT_SOURCE_DIR}/include/infrastructure)

add_library(infrastructure ${INFRASTRUCTURE_SRC_FILES})
target_link_libraries(infrastructure sentry)

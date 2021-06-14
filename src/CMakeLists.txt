find_package(Intl REQUIRED)

add_subdirectory(infrastructure)
add_subdirectory(persistence)

include_directories(${Intl_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_BINARY_DIR})
add_executable(${PROJECT_NAME} main.cpp)
# TODO Starting with cmake 3.20 Intl::Intl is linkable
target_link_libraries(${PROJECT_NAME} mariadbclientpp sentry ${Intl_LIBRARIES})

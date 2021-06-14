find_package(Intl REQUIRED)

add_subdirectory(infrastructure)
add_subdirectory(persistence)

include_directories(${CMAKE_CURRENT_BINARY_DIR})
add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} mariadbclientpp sentry)

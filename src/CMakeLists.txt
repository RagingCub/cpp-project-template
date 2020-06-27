add_subdirectory(infrastructure)
add_subdirectory(persistence)

add_executable(server main.cpp)
target_link_libraries(server mariadbclientpp sentry)

set(PERSISTENCE_SRC_FILES persistence.cpp
        migration/migration.cpp migration-executor.cpp
        migration/2020-06-27_initial-create.hpp)

include_directories(${PROJECT_SOURCE_DIR}/include/persistence)

add_executable(persistence ${PERSISTENCE_SRC_FILES})
target_link_libraries(persistence mariadbclientpp)

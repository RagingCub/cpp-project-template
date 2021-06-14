# Create config.h
message(STATUS "Generating config.h")

# locale dir
if (${CMAKE_BUILD_TYPE} MATCHES Debug)
    set(PACKAGE_LOCALEDIR ${CMAKE_BINARY_DIR}/share/locale)
else ()
    set(PACKAGE_LOCALEDIR ${CMAKE_INSTALL_FULL_LOCALEDIR})
endif ()

# textdomain
set(GETTEXT_PACKAGE ${PROJECT_NAME})

# resources directory
set(RESOURCES_DIR ${PROJECT_SOURCE_DIR}/resources)

# generate config.h
set(CONFIG_H ${CMAKE_CURRENT_BINARY_DIR}/config.h)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/cmake/config.h.in ${CMAKE_CURRENT_BINARY_DIR}/src/config.h)

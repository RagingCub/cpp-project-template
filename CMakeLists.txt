cmake_minimum_required(VERSION 3.14)
project(cpp_project_template)

set(CMAKE_CXX_STANDARD 17)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# tell cmake where its modules can be found in our project directory
list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

# set install directory variable as defined by the GNU Coding Standards.
# e.g. CMAKE_INSTALL_DATAROOTDIR; CMAKE_INSTALL_FULL_BINDIR;
# CMAKE_INSTALL_FULL_DOCDIR...
include(GNUInstallDirs)

# create a dependency graph
include(DependencyGraph)

# set CMake options that the user can optionally select ON or OFF
include(ProjectOptions)

# find dependencies
include(ProjectDependencies)

# create config.h
include(ProjectConfig_h)

add_subdirectory(src)
add_subdirectory(po)
if (BUILD_TESTING)
    enable_testing()

    add_subdirectory(test)
endif ()

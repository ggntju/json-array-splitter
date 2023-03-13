cmake_minimum_required (VERSION 3.0)
set (JSON-ARRAY-SPLITTER_VERSION_MAJOR 1)
set (JSON-ARRAY-SPLITTER_VERSION_MINOR 0)

project (JSON-ARRAY-SPLITTER VERSION ${JSON-ARRAY-SPLITTER_VERSION_MAJOR}.${JSON-ARRAY-SPLITTER_VERSION_MINOR} LANGUAGES CXX)

set (CMAKE_CXX_STANDARD 11)
include_directories ("${PROJECT_SOURCE_DIR}/include/")
include_directories ("${PROJECT_SOURCE_DIR}/include/util/")
include_directories ("${PROJECT_SOURCE_DIR}/include/nlohmann/")
file(GLOB_RECURSE DIR_SRCS "./src/*.cpp")

add_executable(JSON-ARRAY-SPLITTER ${DIR_SRCS})
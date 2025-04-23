cmake_minimum_required(VERSION 3.10)
project(lazy-orm-wrapper VERSION 0.0.1 LANGUAGES CXX)
add_definitions (-Dwrapper_version="${CMAKE_PROJECT_VERSION}")

include(CheckIncludeFileCXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(lazyorm CONFIG REQUIRED)
# TODO: remove set lazyorm_INCLUDE_DIRS
set(lazyorm_INCLUDE_DIRS "/home/mmjvox/dev-libs/install/include")
message("sss: ${lazyorm_INCLUDE_DIRS}")
include_directories(${lazyorm_INCLUDE_DIRS})


add_library(lazy-orm-wrapper SHARED
    MariadbLazyWrapper.cpp
    DbVariantWrapper.cpp
    Utils.cpp
    WhereFilterWrapper.cpp)
set_target_properties(lazy-orm-wrapper PROPERTIES OUTPUT_NAME "lazy-orm-wrapper")

target_link_libraries(lazy-orm-wrapper PRIVATE ${lazyorm_LIBRARIES})

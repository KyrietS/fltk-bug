cmake_minimum_required(VERSION 3.15)
include(FetchContent)

FetchContent_Declare(
        fltk
        GIT_REPOSITORY https://github.com/fltk/fltk.git
        GIT_TAG master
)


project(FltkScale125Bug)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT FltkScale125Bug)
set(FLTK_BUILD_FLUID OFF)
set(FLTK_BUILD_FLTK_OPTIONS OFF)
set(FLTK_BUILD_TEST OFF)
FetchContent_MakeAvailable(
        fltk
)

add_executable(FltkScale125Bug main.cpp)
target_include_directories(FltkScale125Bug PRIVATE ${fltk_SOURCE_DIR})
target_include_directories(FltkScale125Bug PRIVATE ${fltk_BINARY_DIR})
target_link_libraries(FltkScale125Bug fltk)

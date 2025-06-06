# CMake minimum version setup
cmake_minimum_required(VERSION 3.16)

# Project basic information setup
project(CarNewt VERSION 0.1.0 LANGUAGES C CXX)

# Setting up c++ standard
set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_STANDARD_REQUIRED ON)

# Setting up source directory and source files
set (source_dir "${PROJECT_SOURCE_DIR}/src/")
set (test_dir "${PROJECT_SOURCE_DIR}/tests/")

file (GLOB source_files "${source_dir}/*.cpp")
file (GLOB test_files "${test_dir}/*.cpp")


# Adding source files to executable 
add_executable(CarNewt "${source_files}")

# Including include directory
target_include_directories(CarNewt PRIVATE include)

# Disable Wayland on Linux for GLFW (cross-platform fix)
if(UNIX AND NOT APPLE)
    set(GLFW_BUILD_WAYLAND OFF CACHE BOOL "Disable Wayland support" FORCE)
endif()

# Setup GLFW
add_subdirectory(libs/glfw)
target_link_libraries(CarNewt PRIVATE glfw)

# Setup GLAD
add_library(glad libs/glad/src/glad.c)
target_include_directories(glad PUBLIC libs/glad/include)
target_link_libraries(CarNewt PRIVATE glad)

# Setup OpenGL
find_package(OpenGL REQUIRED)
target_link_libraries(CarNewt PRIVATE OpenGL::GL)

# Setup GLM
target_include_directories(CarNewt PRIVATE libs/glm)

# Enabling testing via CTest
include(CTest)
enable_testing()

# Turn on fetching
Include(FetchContent)

# Fetch Catch2
FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.4.0 # or a later release
)
FetchContent_MakeAvailable(Catch2)

# Create an example test case
add_executable(ExampleTest "${test_files}")
target_link_libraries(ExampleTest PRIVATE Catch2::Catch2WithMain)
add_test(NAME CarNewtTests COMMAND ExampleTest)

# Setting up CPack
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

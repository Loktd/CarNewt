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

file (GLOB_RECURSE source_files CONFIGURE_DEPENDS "${source_dir}/*.cpp")
file (GLOB test_files "${test_dir}/*.cpp")

# Adding source files to executable 
add_executable(CarNewt "${source_files}")

# Including include directory
target_include_directories(CarNewt PRIVATE include)

# Turn on fetching
Include(FetchContent)

FetchContent_Declare(
    glad
    GIT_REPOSITORY https://github.com/Dav1dde/glad.git
    GIT_TAG        v2.0.6
    GIT_PROGRESS   TRUE
    SOURCE_SUBDIR  cmake
)
FetchContent_MakeAvailable(glad)
glad_add_library(glad_gl_core_33 STATIC REPRODUCIBLE LOADER API gl:core=3.3)
target_link_libraries(CarNewt PRIVATE glad_gl_core_33)

# Disable Wayland on Linux for GLFW (cross-platform fix)
FetchContent_Declare(
  glfw
  GIT_REPOSITORY https://github.com/glfw/glfw.git
  GIT_TAG        3.3.8
)
FetchContent_MakeAvailable(glfw)
target_link_libraries(CarNewt PRIVATE glfw)

FetchContent_Declare(
  glm
  GIT_REPOSITORY https://github.com/g-truc/glm.git
  GIT_TAG        0.9.9.8
)
FetchContent_MakeAvailable(glm)

target_include_directories(CarNewt PRIVATE
  ${glfw_SOURCE_DIR}/include
  ${glad_SOURCE_DIR}/include
  ${glm_SOURCE_DIR}
)

# Setup OpenGL
find_package(OpenGL REQUIRED)
target_link_libraries(CarNewt PRIVATE OpenGL::GL)

# Enabling testing via CTest
include(CTest)
enable_testing()

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

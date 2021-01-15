cmake_minimum_required(VERSION 3.10)

project(animals)

set(CMAKE_CXX_FLAGS "-std=c++11")

if (NOT DEFINED ENV{PATH})
	message(FATAL_ERROR "Env 'PATH' is mandatory")
endif()

if (DEFINED ENV{PATH})
	set(ENV_PATH ENV{PATH})
	message(STATUS "Env PATH: PATH")
endif()

# specify the installation directory
if (CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
	message(STATUS "Setting default CMAKE_INSTALL_PREFIX path to ${CMAKE_BINARY_DIR}/install")
	set(CMAKE_INSTALL_PREFIX "${CMAKE_BINARY_DIR}/install" CACHE STRING "The path to use for make install" FORCE)
endif()

# path to output libary/bin
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/output)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/output)

# list all source file
aux_source_directory(src/api LIB_SOURCE)
aux_source_directory(src/ TARGET_SOURCE)
#file(GLOB LIB_SOURCE src/api/*.cpp)
#file(GLOB TARGET_SOURCE src/*.cpp)

# generate library
add_library(${PROJECT_NAME} SHARED ${LIB_SOURCE})
target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/include)

# generate binary
add_executable(demo ${TARGET_SOURCE})
target_link_libraries(demo animals)
target_include_directories(demo PRIVATE ${PROJECT_SOURCE_DIR}/include)

# install
install (TARGETS demo
    DESTINATION bin)

install (TARGETS ${PROJECT_NAME}
    LIBRARY DESTINATION lib)

# Header files
install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/
    DESTINATION include)

# Config
install (FILES ${PROJECT_SOURCE_DIR}/conf/config.yaml
    DESTINATION etc)

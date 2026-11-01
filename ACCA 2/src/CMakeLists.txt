cmake_minimum_required(VERSION 3.20)
project(src C)

set(CMAKE_C_STANDARD 11)

# Kompilasi main.c sebagai entry point utama
add_executable(src main.c)

# Pastikan file data tersedia di direktori runtime (cmake-build-debug)
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/databuku.txt")
    file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/databuku.txt" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")
endif()
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/history.txt")
    file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/history.txt" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")
endif()

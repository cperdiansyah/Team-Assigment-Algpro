cmake_minimum_required(VERSION 3.20)
project(src C)

set(CMAKE_C_STANDARD 11)

# Karena main.c sudah langsung me-include slot_1 s.d. slot_5,
# hanya main.c yang perlu dikompilasi ke executable.
add_executable(src main.c)

# apt install gcc-mingw-w64
# cmake -GNinja -DCMAKE_TOOLCHAIN_FILE=../.CMake/toolchain_windows-amd64.cmake ..

set(CMAKE_SYSTEM_NAME Windows)
set(CMAKE_SYSTEM_PROCESSOR AMD64)
set(CMAKE_CROSSCOMPILING ON)

set(PREFIX x86_64-w64-mingw32)
set(CMAKE_C_COMPILER ${PREFIX}-gcc)

set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)

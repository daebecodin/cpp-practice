# C++ Playground

This directory contains small, focused C++ programs for practicing language
features. Each `.cpp` file normally becomes its own executable. The examples
are grouped by topic, such as arrays, strings, type deduction, and vectors.

All directories share the CMake utilities in
[`cmake/CppPlayground.cmake`](cmake/CppPlayground.cmake). The shared file sets
the C++ version, enables warnings, exports compile commands, and connects every
executable to the precompiled header in `../include/pch.h`.

## Requirements

- CMake 3.20 or newer
- A compiler with C++20 support, such as AppleClang, Clang, or GCC

Check the installed tools with:

```sh
cmake --version
c++ --version
```

## Build the entire playground

Run these commands from this `playground` directory:

```sh
cmake -S . -B cmake-build-debug -DCMAKE_BUILD_TYPE=Debug
cmake --build cmake-build-debug -j 4
```

The first command configures the project. The second compiles all enabled
examples. Re-run the build command after changing a source file.

To build only one executable, pass its target name:

```sh
cmake --build cmake-build-debug --target c_string_func
cmake --build cmake-build-debug --target vector_basics
```

List the available targets with:

```sh
cmake --build cmake-build-debug --target help
```

## Run an executable

Executables are placed under the build directory using the same topic layout
as the source tree. For example:

```sh
./cmake-build-debug/c-string/c_string_func
./cmake-build-debug/strings/cctype_functions
./cmake-build-debug/vector/vector_basics
./cmake-build-debug/vector/iterators/binary_search
```

An executable created from a `.cpp` file in the playground root is placed
directly in `cmake-build-debug`.

Some programs read from standard input. Start the executable and then enter
the values requested by that example. Press Control-D to signal end-of-input
when an example reads until EOF.

## Build one directory by itself

Every directory containing a `CMakeLists.txt` can be configured independently.
For example, to work only on vector examples:

```sh
cmake -S vector -B vector/cmake-build-debug -DCMAKE_BUILD_TYPE=Debug
cmake --build vector/cmake-build-debug -j 4
./vector/cmake-build-debug/vector_basics
```

This also works for nested directories:

```sh
cmake -S vector/iterators -B vector/iterators/cmake-build-debug
cmake --build vector/iterators/cmake-build-debug --target binary_search
./vector/iterators/cmake-build-debug/binary_search
```

## Change the C++ version

C++20 is the default. Override it while configuring with
`CPP_PLAYGROUND_CXX_STANDARD`:

```sh
cmake -S . -B cmake-build-debug -DCPP_PLAYGROUND_CXX_STANDARD=23
cmake --build cmake-build-debug -j 4
```

The setting is saved in that build directory. Configure again with a different
value to change it:

```sh
cmake -S . -B cmake-build-debug -DCPP_PLAYGROUND_CXX_STANDARD=17
```

To change the default for all new builds, edit `CPP_PLAYGROUND_CXX_STANDARD`
near the top of `cmake/CppPlayground.cmake`.

## Precompiled header

The shared precompiled header is `../include/pch.h`. Every executable created
through `cpp_playground_add_executable()` automatically uses it and receives
the correct include directory. Source files may therefore use:

```cpp
#include "pch.h"
```

CMake supplies the header automatically as a precompiled header as well, so an
explicit include is optional unless it makes the example clearer.

If an editor reports that `pch.h` cannot be found, configure the project first
and restart its C++ language server. The `.clangd` file points clangd to
`cmake-build-debug/compile_commands.json`.

## Add a new example

Add a `.cpp` file with a `main()` function to an existing topic directory:

```cpp
#include "pch.h"

int main()
{
    std::cout << "Hello, C++!\n";
}
```

The filename becomes the CMake target and executable name. For example,
`arrays/pointer_example.cpp` creates the `pointer_example` target. CMake uses
`CONFIGURE_DEPENDS`, so the next build automatically notices newly added
source files.

For a new first-level topic directory, add this `CMakeLists.txt` beside its
`.cpp` files:

```cmake
cmake_minimum_required(VERSION 3.20)

if(CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
    project(cpp_playground_topic_name LANGUAGES CXX)
endif()

include("${CMAKE_CURRENT_LIST_DIR}/../cmake/CppPlayground.cmake")

cpp_playground_add_executables()
cpp_playground_add_child_directories()
```

If a source file is only a note, stub, or helper and does not have `main()`,
exclude it from automatic executable creation:

```cmake
cpp_playground_add_executables(EXCLUDE unfinished_example)
```

For an executable made from multiple source files, list them explicitly:

```cmake
cpp_playground_add_executable(
    example_name
    SOURCES main.cpp helper.cpp
)
```

## Project layout

```text
cpp-playground/
├── include/
│   └── pch.h
└── playground/
    ├── CMakeLists.txt
    ├── README.md
    ├── cmake/
    │   └── CppPlayground.cmake
    ├── arrays/
    ├── c-string/
    ├── strings/
    ├── vector/
    └── ...
```

Generated files belong in a build directory such as `cmake-build-debug`; keep
them separate from the source files.

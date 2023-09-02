# NVL-LMS Web API Project

This project containes the source code for the Cloud Agnostic, Novac Learning - LMS.

## C++ Standard

This project utilizes C++20 standard and above.

## Web Framework

This project uses the Drogon Web Framework (<https://drogon.org/>).

## Build Instructions

To build this project, you need the following installed in your machine:
gcc - 12+
cmake - 3.26+

Run the following commands from within the "build" folder.

```bash
cmake .. && make
```

## Recommened IDE

Use Visual Studio code. Most preferably Linux (Debian based, Arch, RHEL Based) OS is preferred.
The following extensions are recommended:

* ms-vscode.cpptools
* ms-vscode.cpptools-extension-pack
* ms-vscode.cpptools-themes
* twxs.cmake
* ms-vscode.cmake-tools
* ms-vscode.makefile-tools

## Best Practices

Best practices for this project is taken from [CppBestPractices]<https://github.com/cpp-best-practices/cppbestpractices/blob/master/00-Table_of_Contents.md>.

### Build Tool

* We use of [Cmake](http://www.cmake.org/)
  * [Cotire](https://github.com/sakra/cotire/) for build performance
  * [cmakepp](https://github.com/toeb/cmakepp) for enhanced usability
  * [cmake-flags](https://cmake.org/cmake/help/v3.6/command/target_compile_features.html) for C++ standard flags
  * See the [Further Reading](11-Further_Reading.md) section for CMake specific best practices
  * `cmake --build` provides a common interface for compiling your project regardless of platform

### Package Manager

[CPM](https://github.com/cpm-cmake/CPM.cmake/) is the package manager preferred for this project.
CPM is considered because this works well with CMake.

### Static Analyzers

CppCheck is used. [cppcheck](http://cppcheck.sourceforge.net/)
All warnings should be used using the --enable=all flag.
Notes:

* For correct work it requires well formed path for headers, so before usage don't forget to pass: --check-config.
* Finding unused headers does not work with -j more than 1.
* Remember to add --force for code with a lot number of #ifdef if you need to check all of them.

### Continous Integration

[Travis CI](http://travis-ci.org/) is used as it works well with C++.

### Compiler options

Enabling the maximum compiler warnings.

`-Wall -Wextra -Wshadow -Wnon-virtual-dtor -pedantic` - use these and consider the following (see descriptions below)

* `-pedantic` - Warn on language extensions
* `-Wall -Wextra` reasonable and standard
* `-Wshadow` warn the user if a variable declaration shadows one from a parent context
* `-Wnon-virtual-dtor` warn the user if a class with virtual functions has a non-virtual destructor. This helps catch hard to track down memory errors
* `-Wold-style-cast` warn for c-style casts
* `-Wcast-align` warn for potential performance problem casts
* `-Wunused` warn on anything being unused
* `-Woverloaded-virtual` warn if you overload (not override) a virtual function
* `-Wpedantic` (all versions of GCC, Clang >= 3.2) warn if non-standard C++ is used
* `-Wconversion` warn on type conversions that may lose data
* `-Wsign-conversion` (Clang all versions, GCC >= 4.3) warn on sign conversions
* `-Wmisleading-indentation` (only in GCC >= 6.0) warn if indentation implies blocks where blocks do not exist
* `-Wduplicated-cond` (only in GCC >= 6.0) warn if `if` / `else` chain has duplicated conditions
* `-Wduplicated-branches` (only in GCC >= 7.0) warn if `if` / `else` branches have duplicated code
* `-Wlogical-op` (only in GCC) warn about logical operations being used where bitwise were probably wanted
* `-Wnull-dereference` (only in GCC >= 6.0) warn if a null dereference is detected
* `-Wuseless-cast` (only in GCC >= 4.8) warn if you perform a cast to the same type
* `-Wdouble-promotion` (GCC >= 4.6, Clang >= 3.8) warn if `float` is implicitly promoted to `double`
* `-Wformat=2` warn on security issues around functions that format output (i.e., `printf`)
* `-Wlifetime` (only special branch of Clang currently) shows object lifetime issues
* `-Wimplicit-fallthrough` Warns when case statements fall-through. (Included with `-Wextra` in GCC, not in clang)

The *treat warnings as errors* setting is enabled for this project. The flag `-Werror` with GCC / Clang is used.

### Runtime checkers

#### Heap Profiling

We will use [Valgrind](http://www.valgrind.org/). Valgrind is a runtime code analyzer that can detect memory leaks, race conditions, and other associated problems. It is supported on various Unix platforms.

#### CPU profiling

* [Hotspot](https://github.com/KDAB/hotspot) - An intuitive front-end to visualize datas produced by the [perf](https://perf.wiki.kernel.org) CPU profiler.
* [uftrace](https://github.com/namhyung/uftrace) - Can be used to generating function call graphs of a program execution.

### Debugging

[GDB](https://www.gnu.org/software/gdb/) - The GNU debugger, powerful and widely used. This is considered for this project.

### Other Tools

#### Lizard

[Lizard](http://www.lizard.ws/) provides a very simple interface for running complexity analysis against a C++ codebase.

#### Metrix++

[Metrix++](http://metrixplusplus.sourceforge.net/) can identify and report on the most complex sections of your code. Reducing complex code helps you and the compiler understand it better and optimize it better.

#### CNCC

[Customizable Naming Convention Checker](https://github.com/mapbox/cncc) can report on identifiers in your code that do not follow certain naming conventions.

#### ClangFormat

[ClangFormat](http://clang.llvm.org/docs/ClangFormat.html) can check and correct code formatting to match organizational conventions automatically. [Multipart series](https://engineering.mongodb.com/post/succeeding-with-clangformat-part-1-pitfalls-and-planning/) on utilizing clang-format.

#### SourceMeter

[SourceMeter](https://www.sourcemeter.com/) offers a free version which provides many different metrics for your code and can also call into cppcheck.

#### Includes checking

The compiler has to do something with each include directive it sees. Even if it stops as soon as it sees the `#ifndef` include guard, it still had to open the file and begin processing it.

[include-what-you-use](https://github.com/include-what-you-use/include-what-you-use) is a tool that can help you identify which headers you need.

# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/aarch64/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/aarch64/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/melissa/cp_problems/kattis

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/melissa/cp_problems/kattis/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/quantumsuperposition.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/quantumsuperposition.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/quantumsuperposition.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/quantumsuperposition.dir/flags.make

CMakeFiles/quantumsuperposition.dir/quantumsuperposition.cpp.o: CMakeFiles/quantumsuperposition.dir/flags.make
CMakeFiles/quantumsuperposition.dir/quantumsuperposition.cpp.o: /Users/melissa/cp_problems/kattis/quantumsuperposition.cpp
CMakeFiles/quantumsuperposition.dir/quantumsuperposition.cpp.o: CMakeFiles/quantumsuperposition.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/melissa/cp_problems/kattis/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/quantumsuperposition.dir/quantumsuperposition.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/quantumsuperposition.dir/quantumsuperposition.cpp.o -MF CMakeFiles/quantumsuperposition.dir/quantumsuperposition.cpp.o.d -o CMakeFiles/quantumsuperposition.dir/quantumsuperposition.cpp.o -c /Users/melissa/cp_problems/kattis/quantumsuperposition.cpp

CMakeFiles/quantumsuperposition.dir/quantumsuperposition.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/quantumsuperposition.dir/quantumsuperposition.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/melissa/cp_problems/kattis/quantumsuperposition.cpp > CMakeFiles/quantumsuperposition.dir/quantumsuperposition.cpp.i

CMakeFiles/quantumsuperposition.dir/quantumsuperposition.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/quantumsuperposition.dir/quantumsuperposition.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/melissa/cp_problems/kattis/quantumsuperposition.cpp -o CMakeFiles/quantumsuperposition.dir/quantumsuperposition.cpp.s

# Object files for target quantumsuperposition
quantumsuperposition_OBJECTS = \
"CMakeFiles/quantumsuperposition.dir/quantumsuperposition.cpp.o"

# External object files for target quantumsuperposition
quantumsuperposition_EXTERNAL_OBJECTS =

quantumsuperposition: CMakeFiles/quantumsuperposition.dir/quantumsuperposition.cpp.o
quantumsuperposition: CMakeFiles/quantumsuperposition.dir/build.make
quantumsuperposition: CMakeFiles/quantumsuperposition.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/melissa/cp_problems/kattis/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable quantumsuperposition"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/quantumsuperposition.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/quantumsuperposition.dir/build: quantumsuperposition
.PHONY : CMakeFiles/quantumsuperposition.dir/build

CMakeFiles/quantumsuperposition.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/quantumsuperposition.dir/cmake_clean.cmake
.PHONY : CMakeFiles/quantumsuperposition.dir/clean

CMakeFiles/quantumsuperposition.dir/depend:
	cd /Users/melissa/cp_problems/kattis/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/melissa/cp_problems/kattis /Users/melissa/cp_problems/kattis /Users/melissa/cp_problems/kattis/cmake-build-debug /Users/melissa/cp_problems/kattis/cmake-build-debug /Users/melissa/cp_problems/kattis/cmake-build-debug/CMakeFiles/quantumsuperposition.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/quantumsuperposition.dir/depend


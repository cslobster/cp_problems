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
CMAKE_SOURCE_DIR = /Users/melissa/cp_problems/cf

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/melissa/cp_problems/cf/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/103886L.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/103886L.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/103886L.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/103886L.dir/flags.make

CMakeFiles/103886L.dir/103886L.cpp.o: CMakeFiles/103886L.dir/flags.make
CMakeFiles/103886L.dir/103886L.cpp.o: /Users/melissa/cp_problems/cf/103886L.cpp
CMakeFiles/103886L.dir/103886L.cpp.o: CMakeFiles/103886L.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/melissa/cp_problems/cf/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/103886L.dir/103886L.cpp.o"
	/opt/homebrew/bin/g++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/103886L.dir/103886L.cpp.o -MF CMakeFiles/103886L.dir/103886L.cpp.o.d -o CMakeFiles/103886L.dir/103886L.cpp.o -c /Users/melissa/cp_problems/cf/103886L.cpp

CMakeFiles/103886L.dir/103886L.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/103886L.dir/103886L.cpp.i"
	/opt/homebrew/bin/g++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/melissa/cp_problems/cf/103886L.cpp > CMakeFiles/103886L.dir/103886L.cpp.i

CMakeFiles/103886L.dir/103886L.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/103886L.dir/103886L.cpp.s"
	/opt/homebrew/bin/g++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/melissa/cp_problems/cf/103886L.cpp -o CMakeFiles/103886L.dir/103886L.cpp.s

# Object files for target 103886L
103886L_OBJECTS = \
"CMakeFiles/103886L.dir/103886L.cpp.o"

# External object files for target 103886L
103886L_EXTERNAL_OBJECTS =

103886L: CMakeFiles/103886L.dir/103886L.cpp.o
103886L: CMakeFiles/103886L.dir/build.make
103886L: CMakeFiles/103886L.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/melissa/cp_problems/cf/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 103886L"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/103886L.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/103886L.dir/build: 103886L
.PHONY : CMakeFiles/103886L.dir/build

CMakeFiles/103886L.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/103886L.dir/cmake_clean.cmake
.PHONY : CMakeFiles/103886L.dir/clean

CMakeFiles/103886L.dir/depend:
	cd /Users/melissa/cp_problems/cf/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/melissa/cp_problems/cf /Users/melissa/cp_problems/cf /Users/melissa/cp_problems/cf/cmake-build-debug /Users/melissa/cp_problems/cf/cmake-build-debug /Users/melissa/cp_problems/cf/cmake-build-debug/CMakeFiles/103886L.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/103886L.dir/depend


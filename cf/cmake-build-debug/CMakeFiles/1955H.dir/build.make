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
include CMakeFiles/1955H.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/1955H.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/1955H.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/1955H.dir/flags.make

CMakeFiles/1955H.dir/1955H.cpp.o: CMakeFiles/1955H.dir/flags.make
CMakeFiles/1955H.dir/1955H.cpp.o: /Users/melissa/cp_problems/cf/1955H.cpp
CMakeFiles/1955H.dir/1955H.cpp.o: CMakeFiles/1955H.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/melissa/cp_problems/cf/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/1955H.dir/1955H.cpp.o"
	/opt/homebrew/bin/g++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/1955H.dir/1955H.cpp.o -MF CMakeFiles/1955H.dir/1955H.cpp.o.d -o CMakeFiles/1955H.dir/1955H.cpp.o -c /Users/melissa/cp_problems/cf/1955H.cpp

CMakeFiles/1955H.dir/1955H.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/1955H.dir/1955H.cpp.i"
	/opt/homebrew/bin/g++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/melissa/cp_problems/cf/1955H.cpp > CMakeFiles/1955H.dir/1955H.cpp.i

CMakeFiles/1955H.dir/1955H.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/1955H.dir/1955H.cpp.s"
	/opt/homebrew/bin/g++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/melissa/cp_problems/cf/1955H.cpp -o CMakeFiles/1955H.dir/1955H.cpp.s

# Object files for target 1955H
1955H_OBJECTS = \
"CMakeFiles/1955H.dir/1955H.cpp.o"

# External object files for target 1955H
1955H_EXTERNAL_OBJECTS =

1955H: CMakeFiles/1955H.dir/1955H.cpp.o
1955H: CMakeFiles/1955H.dir/build.make
1955H: CMakeFiles/1955H.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/melissa/cp_problems/cf/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 1955H"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/1955H.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/1955H.dir/build: 1955H
.PHONY : CMakeFiles/1955H.dir/build

CMakeFiles/1955H.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/1955H.dir/cmake_clean.cmake
.PHONY : CMakeFiles/1955H.dir/clean

CMakeFiles/1955H.dir/depend:
	cd /Users/melissa/cp_problems/cf/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/melissa/cp_problems/cf /Users/melissa/cp_problems/cf /Users/melissa/cp_problems/cf/cmake-build-debug /Users/melissa/cp_problems/cf/cmake-build-debug /Users/melissa/cp_problems/cf/cmake-build-debug/CMakeFiles/1955H.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/1955H.dir/depend

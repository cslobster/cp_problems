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
include CMakeFiles/837D.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/837D.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/837D.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/837D.dir/flags.make

CMakeFiles/837D.dir/837D.cpp.o: CMakeFiles/837D.dir/flags.make
CMakeFiles/837D.dir/837D.cpp.o: /Users/melissa/cp_problems/cf/837D.cpp
CMakeFiles/837D.dir/837D.cpp.o: CMakeFiles/837D.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/melissa/cp_problems/cf/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/837D.dir/837D.cpp.o"
	/opt/homebrew/bin/g++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/837D.dir/837D.cpp.o -MF CMakeFiles/837D.dir/837D.cpp.o.d -o CMakeFiles/837D.dir/837D.cpp.o -c /Users/melissa/cp_problems/cf/837D.cpp

CMakeFiles/837D.dir/837D.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/837D.dir/837D.cpp.i"
	/opt/homebrew/bin/g++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/melissa/cp_problems/cf/837D.cpp > CMakeFiles/837D.dir/837D.cpp.i

CMakeFiles/837D.dir/837D.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/837D.dir/837D.cpp.s"
	/opt/homebrew/bin/g++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/melissa/cp_problems/cf/837D.cpp -o CMakeFiles/837D.dir/837D.cpp.s

# Object files for target 837D
837D_OBJECTS = \
"CMakeFiles/837D.dir/837D.cpp.o"

# External object files for target 837D
837D_EXTERNAL_OBJECTS =

837D: CMakeFiles/837D.dir/837D.cpp.o
837D: CMakeFiles/837D.dir/build.make
837D: CMakeFiles/837D.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/melissa/cp_problems/cf/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 837D"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/837D.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/837D.dir/build: 837D
.PHONY : CMakeFiles/837D.dir/build

CMakeFiles/837D.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/837D.dir/cmake_clean.cmake
.PHONY : CMakeFiles/837D.dir/clean

CMakeFiles/837D.dir/depend:
	cd /Users/melissa/cp_problems/cf/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/melissa/cp_problems/cf /Users/melissa/cp_problems/cf /Users/melissa/cp_problems/cf/cmake-build-debug /Users/melissa/cp_problems/cf/cmake-build-debug /Users/melissa/cp_problems/cf/cmake-build-debug/CMakeFiles/837D.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/837D.dir/depend

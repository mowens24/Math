# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.31

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
CMAKE_COMMAND = /opt/homebrew/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/mwo/Documents/GitHub/C++/Practice/Math

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/mwo/Documents/GitHub/C++/Practice/Math/build

# Include any dependencies generated for this target.
include third_party/glad/CMakeFiles/glad.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include third_party/glad/CMakeFiles/glad.dir/compiler_depend.make

# Include the progress variables for this target.
include third_party/glad/CMakeFiles/glad.dir/progress.make

# Include the compile flags for this target's objects.
include third_party/glad/CMakeFiles/glad.dir/flags.make

third_party/glad/CMakeFiles/glad.dir/codegen:
.PHONY : third_party/glad/CMakeFiles/glad.dir/codegen

third_party/glad/CMakeFiles/glad.dir/clean:
	cd /Users/mwo/Documents/GitHub/C++/Practice/Math/build/third_party/glad && $(CMAKE_COMMAND) -P CMakeFiles/glad.dir/cmake_clean.cmake
.PHONY : third_party/glad/CMakeFiles/glad.dir/clean

third_party/glad/CMakeFiles/glad.dir/depend:
	cd /Users/mwo/Documents/GitHub/C++/Practice/Math/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/mwo/Documents/GitHub/C++/Practice/Math /Users/mwo/Documents/GitHub/C++/Practice/Math/third_party/glad /Users/mwo/Documents/GitHub/C++/Practice/Math/build /Users/mwo/Documents/GitHub/C++/Practice/Math/build/third_party/glad /Users/mwo/Documents/GitHub/C++/Practice/Math/build/third_party/glad/CMakeFiles/glad.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : third_party/glad/CMakeFiles/glad.dir/depend

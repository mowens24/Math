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

# Utility rule file for NightlyBuild.

# Include any custom commands dependencies for this target.
include third_party/muparser/CMakeFiles/NightlyBuild.dir/compiler_depend.make

# Include the progress variables for this target.
include third_party/muparser/CMakeFiles/NightlyBuild.dir/progress.make

third_party/muparser/CMakeFiles/NightlyBuild:
	cd /Users/mwo/Documents/GitHub/C++/Practice/Math/build/third_party/muparser && /opt/homebrew/bin/ctest -D NightlyBuild

third_party/muparser/CMakeFiles/NightlyBuild.dir/codegen:
.PHONY : third_party/muparser/CMakeFiles/NightlyBuild.dir/codegen

NightlyBuild: third_party/muparser/CMakeFiles/NightlyBuild
NightlyBuild: third_party/muparser/CMakeFiles/NightlyBuild.dir/build.make
.PHONY : NightlyBuild

# Rule to build all files generated by this target.
third_party/muparser/CMakeFiles/NightlyBuild.dir/build: NightlyBuild
.PHONY : third_party/muparser/CMakeFiles/NightlyBuild.dir/build

third_party/muparser/CMakeFiles/NightlyBuild.dir/clean:
	cd /Users/mwo/Documents/GitHub/C++/Practice/Math/build/third_party/muparser && $(CMAKE_COMMAND) -P CMakeFiles/NightlyBuild.dir/cmake_clean.cmake
.PHONY : third_party/muparser/CMakeFiles/NightlyBuild.dir/clean

third_party/muparser/CMakeFiles/NightlyBuild.dir/depend:
	cd /Users/mwo/Documents/GitHub/C++/Practice/Math/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/mwo/Documents/GitHub/C++/Practice/Math /Users/mwo/Documents/GitHub/C++/Practice/Math/third_party/muparser /Users/mwo/Documents/GitHub/C++/Practice/Math/build /Users/mwo/Documents/GitHub/C++/Practice/Math/build/third_party/muparser /Users/mwo/Documents/GitHub/C++/Practice/Math/build/third_party/muparser/CMakeFiles/NightlyBuild.dir/DependInfo.cmake
.PHONY : third_party/muparser/CMakeFiles/NightlyBuild.dir/depend


# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/zouza/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/183.5429.37/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/zouza/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/183.5429.37/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/zouza/Projects/BSTC

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/zouza/Projects/BSTC/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/BSTC.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/BSTC.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/BSTC.dir/flags.make

CMakeFiles/BSTC.dir/main.cpp.o: CMakeFiles/BSTC.dir/flags.make
CMakeFiles/BSTC.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zouza/Projects/BSTC/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/BSTC.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/BSTC.dir/main.cpp.o -c /home/zouza/Projects/BSTC/main.cpp

CMakeFiles/BSTC.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BSTC.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zouza/Projects/BSTC/main.cpp > CMakeFiles/BSTC.dir/main.cpp.i

CMakeFiles/BSTC.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BSTC.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zouza/Projects/BSTC/main.cpp -o CMakeFiles/BSTC.dir/main.cpp.s

CMakeFiles/BSTC.dir/BSTNode.cpp.o: CMakeFiles/BSTC.dir/flags.make
CMakeFiles/BSTC.dir/BSTNode.cpp.o: ../BSTNode.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zouza/Projects/BSTC/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/BSTC.dir/BSTNode.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/BSTC.dir/BSTNode.cpp.o -c /home/zouza/Projects/BSTC/BSTNode.cpp

CMakeFiles/BSTC.dir/BSTNode.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BSTC.dir/BSTNode.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zouza/Projects/BSTC/BSTNode.cpp > CMakeFiles/BSTC.dir/BSTNode.cpp.i

CMakeFiles/BSTC.dir/BSTNode.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BSTC.dir/BSTNode.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zouza/Projects/BSTC/BSTNode.cpp -o CMakeFiles/BSTC.dir/BSTNode.cpp.s

# Object files for target BSTC
BSTC_OBJECTS = \
"CMakeFiles/BSTC.dir/main.cpp.o" \
"CMakeFiles/BSTC.dir/BSTNode.cpp.o"

# External object files for target BSTC
BSTC_EXTERNAL_OBJECTS =

BSTC: CMakeFiles/BSTC.dir/main.cpp.o
BSTC: CMakeFiles/BSTC.dir/BSTNode.cpp.o
BSTC: CMakeFiles/BSTC.dir/build.make
BSTC: CMakeFiles/BSTC.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/zouza/Projects/BSTC/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable BSTC"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/BSTC.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/BSTC.dir/build: BSTC

.PHONY : CMakeFiles/BSTC.dir/build

CMakeFiles/BSTC.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/BSTC.dir/cmake_clean.cmake
.PHONY : CMakeFiles/BSTC.dir/clean

CMakeFiles/BSTC.dir/depend:
	cd /home/zouza/Projects/BSTC/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zouza/Projects/BSTC /home/zouza/Projects/BSTC /home/zouza/Projects/BSTC/cmake-build-debug /home/zouza/Projects/BSTC/cmake-build-debug /home/zouza/Projects/BSTC/cmake-build-debug/CMakeFiles/BSTC.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/BSTC.dir/depend

